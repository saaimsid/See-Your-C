/*
				SEE YOUR C
		C Quiz project by Saaim and Priya
		
		
Questions file is in the format

Question
(Blank Line)
Option 1
Option 2
Option 3
Option 4
(Blank Line)
Correct answer
(Blank Line)


*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#define totques 10
static int score=0;
int i,j,k,choice;
char ch;
int Qno[totques];
struct Ques{
	char ques[200];
	char option[5][200];
	int correct;
}q;
void end(){
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t+-----------------------------+");
	printf("\n\t\t\t\t\t\t\t\t\t|          Coded by:-         |");
	printf("\n\t\t\t\t\t\t\t\t\t+-----------------------------+");
	printf("\n\t\t\t\t\t\t\t\t\t|     Mohd Saaim Siddiqui     |");
	printf("\n\t\t\t\t\t\t\t\t\t|         Priya Juyal         |");
	printf("\n\t\t\t\t\t\t\t\t\t+-----------------------------+\n\n\n");
	getch();
}
void printScore(){
	
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease wait");
	printf("\n\n\t\t\t\t\t\tCalculating your score");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	sleep(1);
	system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tYour Score is %d",score);	
    sleep(1);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t-----------------------------------------------");
    printf("\n\t\t\t\t\t\t\t   Press any key to continue...");
    getch();
}
void showQuestions(){
	char line[200];
    FILE * fp;
    fp = fopen("questions.txt","r");
    if(fp == NULL){
    	printf("\n\n\n\t\t\t Questions File Can't Be OPENED \t\t\t \n\n\n");
	}
	k=1;
	for ( i=0 ; i<=Qno[totques-1] ; i++ ){
	  if(Qno[k-1]==i){	
		system("cls");
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t> Enter 0 to exit");
		printf("\n\n\n\n\n\nQ%d) ",k++);
	
		fgets(line,sizeof(line),fp);
		strcpy(q.ques,line);
		printf("%s\n",q.ques);
		
		fgets(line,sizeof(line),fp);
		
		fgets(line,sizeof(line),fp);
		strcpy(q.option[0],line);
		printf("\n 1) %s",q.option[0]);
			
		fgets(line,sizeof(line),fp);
		strcpy(q.option[1],line);
		printf("\n 2) %s",q.option[1]);
	
		fgets(line,sizeof(line),fp);
		strcpy(q.option[2],line);
		printf("\n 3) %s",q.option[2]);
		
		fgets(line,sizeof(line),fp);
		strcpy(q.option[3],line);	
		printf("\n 4) %s",q.option[3]);
		 		
		fgets(line,sizeof(line),fp);
		
		fgets(line,sizeof(line),fp);	//for correct answer
		strcpy(q.option[4],line);	
		
		fgets(line,sizeof(line),fp);
	
		if(!strcmp(q.option[4],q.option[0]))
		 q.correct=1;
		else if(!strcmp(q.option[4],q.option[1]))
		 q.correct=2;
		else if(!strcmp(q.option[4],q.option[2]))
		 q.correct=3;
		else if(!strcmp(q.option[4],q.option[3]))
		 q.correct=4;
		 
		quesLabel:
		printf("\n\n Enter your choice > ");
		scanf("%d",&choice); 
		 
		if(choice==0){
			printf("\n\n\t\tPress Y to exit \n\t\t   > ");
			char cexit;
			cexit=toupper(getch());
			if(cexit=='Y'){
			
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tYou have ended the quiz.....");
			sleep(1);
			break;
			}
			else{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t> Enter 0 to exit");
				printf("\n\n\n\n\n\n\nQ%d) ",k-1);
				printf("%s",q.ques); 
				printf("\n\n 1) %s",q.option[0]);
				printf("\n 2) %s",q.option[1]);
				printf("\n 3) %s",q.option[2]);
				printf("\n 4) %s",q.option[3]);
				goto quesLabel;
			}	 
		}
		else if(choice>=1 && choice<=4){
			
			if(choice==q.correct)
			 score++;	
		}
		else{
		  printf("\n INVALID OPTION!!!");
		  goto quesLabel;
		}
	}
	else{
			
		fgets(line,sizeof(line),fp);	//Question
		fgets(line,sizeof(line),fp);	//blank line
		fgets(line,sizeof(line),fp);	//Option 1
		fgets(line,sizeof(line),fp);	//Option 2
		fgets(line,sizeof(line),fp);	//Option 3
		fgets(line,sizeof(line),fp);	//Option 4
		fgets(line,sizeof(line),fp);	//blank line
		fgets(line,sizeof(line),fp);	//Correct option
		fgets(line,sizeof(line),fp);	//blank line
		}
	}
	fclose(fp);
	printScore();
}
void generateNumbers(){
		
	srand(time(NULL));
	for( i=0 ; i<totques ; i++){
		Qno[i]=rand()%140;
		for( j=i-1 ; j>=0 ; j-- ){
			if(Qno[i]==Qno[j]){
				i--;
				break;
			}
		}		
	}  
	
	int temp;
	for( i=0 ; i<totques ; i++){
		for( j=0 ; j<totques-1 ; j++){
			if(Qno[j+1]<Qno[j]){
				temp = Qno[j+1];
				Qno[j+1] = Qno[j];
				Qno[j] = temp;
			}
		}
	}  
	showQuestions();
}
void rules()
{
	system("cls");
	printf("\n\n\n\n\n\n\n");
	printf("\n\t\t\t\t\t\t==============================================================================\n");
	printf("\n\t\t\t\t\t\t\t\t\t           INSTRUCTIONS\n");	
	printf("\n\t\t\t\t\t\t==============================================================================\n");
	sleep(0.5);
	printf("\n\n\t\t\t\t\t\t   -> This quiz contains 10 multiple choice questions.");
	sleep(0.5);
	printf("\n\n\t\t\t\t\t\t   -> Every correct answer scores you +1.");
	sleep(0.5);
	printf("\n\n\t\t\t\t\t\t   -> There's no negative marking.");
	sleep(0.5);
	printf("\n\n\t\t\t\t\t\t   -> Enter your choices only in digits 1,2,3 & 4.");
	sleep(0.5);
	printf("\n\n\t\t\t\t\t\t   -> Press enter to confirm your choice after you have entered your choice.");
	sleep(0.5);
	printf("\n\n\t\t\t\t\t\t   -> Press 0 if you wish to quit the game in between.\n"); 
	printf("\n\t\t\t\t\t\t==============================================================================\n");
	printf("\n\t\t\t\t\t\t                 >  Press any key to continue\n");
	printf("\n\t\t\t\t\t\t==============================================================================\n");
	getch();
	generateNumbers();
}
void login(){
	char username[15];
	char password[10];
	login:
	system("cls");
	printf("\n\n\n\n\n\n\n");
	printf("\n\n\n\t\t\t\t\t\t\t\t-------------------------------------");
	printf("\n\t\t\t\t\t\t\t\t                LOGIN");
	printf("\n\t\t\t\t\t\t\t\t-------------------------------------");
	printf("\n\n\n\t\t\t\t\t\t\t\t\tUsername : ");
	gets(username);
	printf("\n\t\t\t\t\t\t\t\t\tPassword : ");
 	i=0;
 	do{ 
        password[i]=getch(); 
        if(password[i]!='\r'){ 
            printf("*"); 
        } 
        i++; 
    }while(password[i-1]!='\r'); 
    password[i-1]='\0'; 
	if(!strcmp(username,"bvicam@2002")){
		if(!strcmp(password,"19121997")){
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\tLogin successful");
			sleep(1);
			rules();
			
		}
		else{
			printf("\n\n\t\t\t\t\t\t\t\t\t   Wrong password");
			printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t > Press 0 to exit...");
			printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t > Press any key to continue...");
			if(getch()=='0')
			{
				ch='0';
				end();
			}
			else
			 goto login;
		}
	}
	else{
		printf("\n\n\t\t\t\t\t\t\t\t\t   Wrong Username");
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t > Press 0 to exit...");
		printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t > Press any key to continue...");
		if(getch()=='0')
		 end();
		else
		 goto login;
	}
}
void menu()
{
	do{
		system("cls");
		printf("\n\n\n\n\n\n\n\n");	
		printf("\n\t\t\t\t\t\t\t\t***************************************");
		printf("\n\t\t\t\t\t\t\t\t*                                     *");
		printf("\n\t\t\t\t\t\t\t\t*             SEE YOUR C              *");
		printf("\n\t\t\t\t\t\t\t\t*                                     *");
	    printf("\n\t\t\t\t\t\t\t\t***************************************\n");
	    printf("\n\t\t\t\t\t\t\t\t\t        Welcome           ");
		printf("\n\t\t\t\t\t\t\t\t\t          to             ");
	    printf("\n\t\t\t\t\t\t\t\t\t     The C-Quiz App      \n");
	    printf("\n\t\t\t\t\t\t\t\t________________________________________\n");
	    printf("\n\t\t\t\t\t\t\t\t   >  Press 0 to quit          ");
		printf("\n\t\t\t\t\t\t\t\t   >  Press any key to continue");
	    printf("\n\t\t\t\t\t\t\t\t________________________________________\n\n");
	    ch=getch();
	    if(ch!='0')
	     login();
	    else
	     end();
	}while(ch!='0');
}
int main(){
	
	menu();	
	return 0;
}


