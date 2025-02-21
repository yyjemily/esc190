#include "autocomplete.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int comp(const void *a, const void *b, int len_substr) {
    term *term_a = (term *)a;
    term *term_b = (term *)b;
    return strncmp(term_a->term, term_b->term, len_substr);
}

int compweights(const void *a, const void *b) {
    term *term_a = (term *)a;
    term *term_b = (term *)b;
    return term_a->weight - term_b->weight;    
}

int main(void)
{
    // struct term *terms; //declare as struct to allocate memory
    // int nterms;
    // read_in_terms(&terms, &nterms, "cities.txt");
    double weights[] = {14608512, 13076300, 12691836, 12294193, 11624219, 
                         11174257, 10927986, 10444527, 10381222, 10356500, 
                         10349312, 10021295, 9000000};
    const char *cities[] = {
        "Shanghai, China",
        "Buenos Aires, Argentina",
        "Mumbai, India",
        "Mexico City, Distrito Federal, Mexico",
        "Karachi, Pakistan",
        "İstanbul, Turkey",
        "Delhi, India",
        "Manila, Philippines",
        "Moscow, Russia",
        "Dhaka, Bangladesh",
        "Seoul, South Korea",
        "São Paulo, Brazil",
        "Lagos, Nigeria"
    };

    // Dynamically allocate memory for the terms array
    term *terms = (term *)malloc(13 * sizeof(term));
    term t[13];

    for (int i = 0; i< 13; i++) {
        strcpy(t[i].term, cities[i]);  // Copy city name to struct's term
        t[i].weight = weights[i];      // Assign the weight to the struct's weight
    }
    
///////NOT WORKING EHREE???????//////
    qsort(t, 13, sizeof(term), comp); //QSORT NOT WORKING FLK
    printf("%d", lowest_match(t, 13, "Shan")); 
    
    //lowest_match(terms, nterms, "Tor");
    //highest_match(terms, nterms, "Tor");
    
    struct term *answer;
    int n_answer;
    //autocomplete(&answer, &n_answer, terms, nterms, "Tor");
    //free allocated blocks here -- not required for the project, but good practice
    
    return 0;
}
