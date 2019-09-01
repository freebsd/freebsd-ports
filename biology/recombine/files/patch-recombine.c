--- recombine.c.orig	2019-08-03 09:14:33 UTC
+++ recombine.c
@@ -169,7 +169,7 @@ void openfile(FILE **fp, char *filename,
         file[0] = '\0';
         while (file[0] =='\0'){
           fprintf(stdout,"Please enter a new filename>");
-          gets(file);
+          fgets(file,100,stdin);
           }
         break;
       case 'w':
@@ -177,7 +177,7 @@ void openfile(FILE **fp, char *filename,
         file[0] = '\0';
         while (file[0] =='\0'){
           fprintf(stdout,"Please enter a new filename>");
-          gets(file);
+          fgets(file,100,stdin);
           }
         break;
       }
@@ -1864,28 +1864,28 @@ if (strchr("#FLAHONESPGUMVRTD",ch) != NU
       case 'R':
          do {
             printf("Relative mutation rate of trait?\n");
-            gets(input);
+            fgets(input,LINESIZE,stdin);
             op->mutrait = atof(input);
          } while (op->mutrait <= 0.0);
          break;
       case 'T':
          do {
             printf("Ratio of forward to back trait mutation?\n");
-            gets(input);
+            fgets(input,LINESIZE,stdin);
             op->traitratio = atof(input);
          } while (op->traitratio <= 0.0);
          break;
       case 'D':
          do {
             printf("Frequency of trait?\n");
-            gets(input);
+            fgets(input,LINESIZE,stdin);
             op->pd = atof(input);
          } while (op->pd <= 0.0 || op->pd >= 1.0);
          break;
       case 'A':
          do {
             printf("Number of drops while resimulating (0-2)?\n");
-            gets(input);
+            fgets(input,LINESIZE,stdin);
             op->hapdrop = atol(input);
          } while (op->hapdrop != 0 && op->hapdrop != 1 && op->hapdrop != 2); 
       default:
@@ -1972,7 +1972,7 @@ if(strchr("#NQPDITFCRVHWZS12L34AB",ch) !
       case 'T':
          do {
             printf("Transition/transversion ratio?\n");
-            gets(input);
+            fgets(input,LINESIZE,stdin);
             locus_ttratio = atof(input);
             if (locus_ttratio < 0.5)
                printf("TTratio cannot be less than 0.5\n");
@@ -1991,13 +1991,13 @@ if(strchr("#NQPDITFCRVHWZS12L34AB",ch) !
          op->panel = !op->panel;
          if (op->panel) {
             printf("Number of populations?\n");
-            gets(input);
+            ;
             *numpop = atol(input);
             op->numpanel = (long *)calloc(*numpop,sizeof(long));
             for(i = 0; i < *numpop; i++) {
                printf("Number of panel haplotypes for population");
                printf(" %ld?\n",i+1);
-               gets(input);
+               fgets(input,LINESIZE,stdin);
                op->numpanel[i] = atol(input);
             }
          } else
@@ -2012,7 +2012,7 @@ if(strchr("#NQPDITFCRVHWZS12L34AB",ch) !
          if (op->ctgry) {
             do {
                printf("Number of categories ?");
-               gets(input);
+               fgets(input,LINESIZE,stdin);
                op->categs = atoi(input);
             } while (op->categs < 1);
             free(op->rate);
@@ -2091,7 +2091,7 @@ if(strchr("#NQPDITFCRVHWZS12L34AB",ch) !
          if (!op->watt) {
             do {
                printf("Initial theta estimate?\n");
-               gets(input);
+               fgets(input,LINESIZE,stdin);
                theta0 = atof(input);
             } while (theta0 <= 0.0);
          }
@@ -2099,7 +2099,7 @@ if(strchr("#NQPDITFCRVHWZS12L34AB",ch) !
       case 'Z':
          printf("What recombination rate?\n");
          do {
-            gets(input);
+            fgets(input,LINESIZE,stdin);
             rec0 = atof(input);
             if (rec0 < 0.0)
                printf("recombination rate must be non-negative\n");
@@ -2108,7 +2108,7 @@ if(strchr("#NQPDITFCRVHWZS12L34AB",ch) !
       case 'S':
          do {
             printf("How many Short Chains?\n");
-            gets(input);
+            fgets(input,LINESIZE,stdin);
             op->numchains[0] = atoi(input);
             if (op->numchains[0] < 0)
             printf("Must be non-negative\n");
@@ -2118,7 +2118,7 @@ if(strchr("#NQPDITFCRVHWZS12L34AB",ch) !
          done = FALSE;
          while (!done) {
             printf("How often to sample trees?\n");
-            gets(input);
+            fgets(input,LINESIZE,stdin);
             op->increm[0] = atoi(input);
             if (op->increm[0] > 0) done = TRUE;
             else printf("Must be a positive integer\n");
@@ -2128,7 +2128,7 @@ if(strchr("#NQPDITFCRVHWZS12L34AB",ch) !
          done = FALSE;
          while (!done) {
             printf("How many short steps?\n");
-            gets(input);
+            fgets(input,LINESIZE,stdin);
             op->steps[0] = atoi(input);
             if (op->steps[0] > 0) done = TRUE;
             else printf("Must be a positive integer\n");
@@ -2137,7 +2137,7 @@ if(strchr("#NQPDITFCRVHWZS12L34AB",ch) !
       case 'L':
          do {
             printf("How many Long Chains?\n");
-            gets(input);
+            fgets(input,LINESIZE,stdin);
             op->numchains[1] = atoi(input);
             if (op->numchains[1] < 1)
             printf("Must be a positive integer\n");
@@ -2147,7 +2147,7 @@ if(strchr("#NQPDITFCRVHWZS12L34AB",ch) !
          done = FALSE;
          while (!done) {
             printf("How often to sample trees?\n");
-            gets(input);
+            fgets(input,LINESIZE,stdin);
             op->increm[1] = atoi(input);
             if (op->increm[1] > 0) done = TRUE;
             else printf("Must be a positive integer\n");
@@ -2157,7 +2157,7 @@ if(strchr("#NQPDITFCRVHWZS12L34AB",ch) !
          done = FALSE;
          while (!done) {
             printf("How many long steps?\n");
-            gets(input);
+            fgets(input,LINESIZE,stdin);
             op->steps[1] = atoi(input);
             if (op->steps[1] > 0) done = TRUE;
             else printf("Must be a positive integer\n");
@@ -2239,7 +2239,7 @@ do {
    if (menu1) print_startmenu(op,writeout);
    else {print_datamenu(op); print_searchmenu(op);}
    print_menuend();
-   gets(input);
+   fgets(input,LINESIZE,stdin);
    ch = toupper((int)input[0]);
    done = (ch == 'Y');
    if (!done) {
