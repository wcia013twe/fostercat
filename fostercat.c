#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Family{

    int position;
    char catOwned[19];

};

int main(){

    int* cats;
    int cages, totalWeeks;
    struct Family *lee, *lyn, *eve;

    //first number in input represents number of cages, second represents weeks
    scanf("%d", &cages);
    scanf("%d", &totalWeeks);

    char** arr = (char **)malloc(cages*  sizeof(char)); //Create
    if (arr != NULL) {
        //each string can have a name up to 19 characters

        for(int i =0; i < cages; i++){ //up to 19 chars

            arr[i] = (char *) calloc(19, sizeof(char));

            char nameString[19];
            scanf("%s", &nameString);

            strcpy(arr[i], nameString);
        }
    }
    else
    {
        fprintf(stderr, "WARNING: Allocation failed.\n"); // Warn user of failure
    }

    for (int i = 0; i<cages; i++){

        if (arr[i] == '\0'){
            printf("No cat found.");
        }
        else{
            printf("%s\n",arr[i]);
        }
    }


    int week = 0;

    //set the index of the cage the family starts adoption
    lee->position = 0;
    lyn->position = 1;
    eve->position = 2;
    
    while(week < totalWeeks)    {

        for (int day = 0; day < 3;day++){ //disregard all other days of the week with no adoption

            switch(day)
            {
                case 0: //Lee family adopts on Monday

                    if(week > 0){
                        if(lee->catOwned[0] != '\0'){
                            strcpy(arr[lee->position], lee->catOwned); //drop off cat if the family has one
                        }
                        lee->position += 2; //move two cages down
                        if (lee->position + 1 > cages) lee->position - cages; //adjust index of the cages if it exceeds the total number of cages
                        if (arr[lee->position][0] == '\0') continue; //if there if no cat, don't adopt
                    }
                    strcpy(lee->catOwned, arr[lee->position]); //copys the name of the cat 
                    strcat(lee->catOwned, "Lee");   //concatenate last name onto cat
                    continue;

                case 1: 

                    if(week > 0){
                        if(lyn->catOwned[0] != '\0'){
                            strcpy(arr[lyn->position], lyn->catOwned); //drop off cat if the family has one
                        }
                        lyn->position += 3; //move three cages down
                        if (lyn->position + 1 > cages) lyn->position - cages; //adjust index of the cages if it exceeds the total number of cages
                        if (arr[lyn->position][0] == '\0') continue; //if there if no cat, don't adopt
                    }
                    strcpy(lyn->catOwned, arr[lyn->position]); //copys the name of the cat 
                    strcat(lee->catOwned, "Lyn");   //concatenate last name onto cat
                    continue;   
                case 2:

                    if(week > 0){
                        if(eve->catOwned[0] != '\0'){
                            strcpy(arr[eve->position], eve->catOwned); //drop off cat if the family has one
                        }
                        eve->position += 2; //move two cages down
                        if (eve->position + 1 > cages) eve->position - cages; //adjust index of the cages if it exceeds the total number of cages
                        if (arr[eve->position][0] == '\0') continue; //if there if no cat, don't adopt
                    }
                    strcpy(eve->catOwned, arr[eve->position]); //copys the name of the cat 
                    strcat(eve->catOwned, "Eve");   //concatenate last name onto cat
                    continue;
            }
        }
        week++;
    }

    for (int i = 0; i<cages; i++){

        if (arr[i] == '\0'){
            printf("No cat found.");
        }
        else{
            printf("%s\n",arr[i]);
        }
    }

    for (int i = 0; i < cages; i++) // Free the ‘‘rows’’ of the grid
    {
        free(arr[i]);
    }
    free(arr); // Free the initial allocation
    return 0; // Exit the program
}

