#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


void rungame() {
    int play = 1;

    while (play) {
        int ran = (rand() % 3) + 1;
        int x;

        printf("Welcome to the number guessing game!\n");
        printf("Guess a number between 1 and 10, or type \"0\" to exit\n>> ");

        while (1) {
            int result = scanf("%d", &x);

            if(result != 1){
                printf("Please enter an Integer\n>> ");
                while(getchar() != '\n');
                continue;
            }

            if(x > 10){
                printf("Number must be between 0 and 10\n>> ");
                continue;
            }

            if (x == 0) {
                printf("Exiting program now.\n");
                play = 0;
                break;
            }

            if (x == ran) {
                printf("You guessed correctly! Would you like to play again? (y/n)\n>> ");
                char again;
                scanf(" %c", &again);

                if (again == 'y') {
                    break;
                } else if (again == 'n') {
                    printf("Thanks for playing.\n");
                    play = 0;
                    break;
                } else {
                    printf("ERROR. EXITING PROGRAM\n");
                    play = 0;
                    break;
                }
            } else {
                printf("Guess again!\n>> ");
            }
        }
    }
}

int main(void) {
    srand(time(NULL));
    rungame();
    return 0;
}
