--- src/input.c.orig	2005-07-10 09:16:31 UTC
+++ src/input.c
@@ -16,7 +16,6 @@ manually! 
 */
 
 #include <stdio.h>
-#include <malloc.h>
 #include <math.h>
 #include "nrutil.h"
 #include "yagi.h"
@@ -32,8 +31,9 @@ int main(int argc, char **argv)
 	char response, *filename, *notes, *type, data_entry;
 	FILE *fp;
 
-	filename = string(0L, 1000L);
-	notes = string(0L, 1000L);
+#define MAXINPUTLINE 1000
+	filename = string(0L, MAXINPUTLINE);
+	notes = string(0L, MAXINPUTLINE);
 	type = string(0L, 1000L);
 
    while ((c =	getoptions(argc,argv,"h")) != -1)
@@ -56,10 +56,10 @@ int main(int argc, char **argv)
 	printf("\nThis program asks for length, diameter and position of antenna elements then\n");
 	printf("writes them to a file you specify. Data is written in m (metres)\n \n");
 	printf("Enter any notes on this design (up to 400 characters): ");
-	gets(notes);
-	printf("Enter a filename to write data to ");
-	gets(filename);
-	printf("Enter the centre frequency in MHz ");
+	fgets(notes, MAXINPUTLINE-1, stdin);
+ 	printf("Enter a filename to write data to ");
+	fgets(filename, MAXINPUTLINE-1, stdin);
+ 	printf("Enter the centre frequency in MHz ");
 	scanf("%lf", &frequency);
 	printf("Enter the minimum frequency in MHz ");
 	scanf("%lf", &min_f);
