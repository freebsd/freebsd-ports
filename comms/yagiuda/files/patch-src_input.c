--- src/input.c.orig	2005-07-10 09:16:31 UTC
+++ src/input.c
@@ -16,7 +16,7 @@ manually! 
 */
 
 #include <stdio.h>
-#include <malloc.h>
+#include <string.h>
 #include <math.h>
 #include "nrutil.h"
 #include "yagi.h"
@@ -29,12 +29,14 @@ int main(int argc, char **argv)
 	double min_f, max_f, step_f, angular_step;
 	int elements, driven, i, fixed_diameter, boom, parasitic, c, hflg=0, errflg=0;
 	double scale_factor;
-	char response, *filename, *notes, *type, data_entry;
+	char response, *filename, *notes, *type, *str, data_entry;
 	FILE *fp;
 
-	filename = string(0L, 1000L);
-	notes = string(0L, 1000L);
-	type = string(0L, 1000L);
+#define MAXINPUTLINE 1000L
+	filename = string(0L, MAXINPUTLINE);
+	notes = string(0L, MAXINPUTLINE);
+	type = string(0L, MAXINPUTLINE);
+	str = string(0L, MAXINPUTLINE);
 
    while ((c =	getoptions(argc,argv,"h")) != -1)
    switch	(c) 
@@ -56,56 +58,65 @@ int main(int argc, char **argv)
 	printf("\nThis program asks for length, diameter and position of antenna elements then\n");
 	printf("writes them to a file you specify. Data is written in m (metres)\n \n");
 	printf("Enter any notes on this design (up to 400 characters): ");
-	gets(notes);
-	printf("Enter a filename to write data to ");
-	gets(filename);
-	printf("Enter the centre frequency in MHz ");
-	scanf("%lf", &frequency);
+	fgets(notes, MAXINPUTLINE-1, stdin);
+	notes[strcspn(notes, "\n")] = '\0';
+ 	printf("Enter a filename to write data to ");
+	fgets(filename, MAXINPUTLINE-1, stdin);
+	filename[strcspn(filename, "\n")] = '\0';
+ 	printf("Enter the centre frequency in MHz ");
+	fgets(str, MAXINPUTLINE-1, stdin);
+	sscanf(str,"%lf", &frequency);
 	printf("Enter the minimum frequency in MHz ");
-	scanf("%lf", &min_f);
+	fgets(str, MAXINPUTLINE-1, stdin);
+	sscanf(str,"%lf", &min_f);
 	printf("Enter the maximum frequency in MHz ");
-	scanf("%lf", &max_f);
+	fgets(str, MAXINPUTLINE-1, stdin);
+	sscanf(str,"%lf", &max_f);
 	printf("Enter the frequency steps in MHz ");
-	scanf("%lf", &step_f);
+	fgets(str, MAXINPUTLINE-1, stdin);
+	sscanf(str,"%lf", &step_f);
 	if(min_f > frequency)
 		nrerror("The minimum frequency has been set higher than the centre frequency");
 	if(max_f < frequency)
 		nrerror("The maximum frequency has been set lower than the centre frequency");
 	printf("\nData can be entered in imperial (inches) metric (mm) or wavelengths (lambda)\n");
 	printf("Please enter i (for imperial), m (for metric) or w (for wavelengths). ");
-	scanf("%c", &data_entry);
-	scanf("%c", &data_entry);
+	fgets(str, MAXINPUTLINE-1, stdin);
+	sscanf(str,"%c", &data_entry);
 	/* The file produced by this is always written in metres.  */
 	if(data_entry=='i' || data_entry=='I')
 	{
 		scale_factor=39.37; /* inches in 1m */
-		type="\"\"";
+		strcpy(type,"\"\"");
 	}
 	else if(data_entry=='m' || data_entry=='m')
 	{
 		scale_factor=1000.0; /* mm in 1m */
-		type="mm";
+		strcpy(type,"mm");
 	}
 	else if(data_entry=='w' || data_entry=='w')
 	{
 		scale_factor=frequency/300; /* wavelegths in 1m */
-		type="lambda";
+		strcpy(type,"lambda");
 	}
 	else
 		exit(1);
 	printf("Enter the number of elements for the antenna ");
-	scanf("%d",&elements);
+	fgets(str, MAXINPUTLINE-1, stdin);
+	sscanf(str,"%d",&elements);
 	/* printf("Enter the number of driven elements ");
-	scanf("%d", &driven); */
+	fgets(str, MAXINPUTLINE-1, stdin);
+	sscanf(str,"%d", &driven); */
 	driven=1;
 	parasitic=elements-driven;
 	d=dmatrix(1L, (long) driven, 1L, 6L);
 	p=dmatrix(1L, (long) parasitic , 1L, 4L);
 	printf("Enter the angular step size in degrees for the gain to be plotted ");
-	scanf("%lf",&angular_step);
+	fgets(str, MAXINPUTLINE-1, stdin);
+	sscanf(str,"%lf",&angular_step);
 	/* printf("Are any of the elements tappered? ");
-	scanf("%c", &response);
-	scanf("%c", &response);
+	fgets(str, MAXINPUTLINE-1, stdin);
+	sscanf(str,"%c", &response);
 	if(response =='y' || response == 'Y')
 	{
 		tappered=TRUE;
@@ -114,12 +125,13 @@ int main(int argc, char **argv)
 	}
 	*/
 	printf("Are all the elements of the same diameter ? ");
-	scanf("%c",&response);
-	scanf("%c",&response);
+	fgets(str, MAXINPUTLINE-1, stdin);
+	sscanf(str,"%c",&response);
 	if(response=='Y' || response =='y')
 	{
 		printf("Enter the diameter of the elements (in %s) ", type);
-		scanf("%lf", &diameter);
+		fgets(str, MAXINPUTLINE-1, stdin);
+		sscanf(str,"%lf", &diameter);
 		fixed_diameter=TRUE;
 	}
 	else
@@ -128,29 +140,35 @@ int main(int argc, char **argv)
 	for(i=1;i<=driven;++i) 
 	{
 		printf("\n\nEnter location of the driven element in %s (wrt. reflector at x=0) ", type);
-		scanf("%lf", &d[i][X]);
+		fgets(str, MAXINPUTLINE-1, stdin);
+		sscanf(str,"%lf", &d[i][X]);
 		d[i][Y]=0;	
 		if( boom != TRUE)
 		{
 			printf("Enter the y position of the driven element (in %s) ", type);
-			scanf("%lf", &d[i][Y]);
+			fgets(str, MAXINPUTLINE-1, stdin);
+			sscanf(str,"%lf", &d[i][Y]);
 		}
 		else
 			d[i][Y]=0.0;
 		printf("Enter length of the driven element (in %s) ", type);
-		scanf("%lf", &d[i][LENGTH]);
+		fgets(str, MAXINPUTLINE-1, stdin);
+		sscanf(str,"%lf", &d[i][LENGTH]);
 		if(fixed_diameter == TRUE)
 			d[i][DIAMETER]=diameter;
 		else
 		{
 			printf("Enter the diameter of the driven element (in %s) ", type);
-			scanf("%lf", &d[i][DIAMETER]);
+			fgets(str, MAXINPUTLINE-1, stdin);
+			sscanf(str,"%lf", &d[i][DIAMETER]);
 		}
 		/*
 		printf("Enter the voltage driving this element ");
-		scanf("%lf", &d[i][VOLTAGE_R]);
+		fgets(str, MAXINPUTLINE-1, stdin);
+		sscanf(str,"%lf", &d[i][VOLTAGE_R]);
 		printf("Enter the phase driving this element ");
-		scanf("%lf", &d[i][VOLTAGE_I]);
+		fgets(str, MAXINPUTLINE-1, stdin);
+		sscanf(str,"%lf", &d[i][VOLTAGE_I]);
 		*/
 		d[i][VOLTAGE_R]=1.0;
 		d[i][VOLTAGE_I]=0.0;
@@ -160,39 +178,46 @@ int main(int argc, char **argv)
 	        if(i==1) /* The reflector */
 		{
 		   printf("\nEnter length of the reflector (in %s) ", type);
-		   scanf("%lf", &p[1][LENGTH]);
+		   fgets(str, MAXINPUTLINE-1, stdin);
+		   sscanf(str,"%lf", &p[1][LENGTH]);
 		   if(boom != TRUE)
 		   {
 			printf("\nEnter the y position of the reflector (in %s) ", type);
-			scanf("%lf", &p[i][Y]);
+		        fgets(str, MAXINPUTLINE-1, stdin);
+			sscanf(str,"%lf", &p[i][Y]);
 		   }
 		   if(fixed_diameter == TRUE)
 			p[i][DIAMETER]=diameter;
 		   else
 		   {
 			printf("Enter the diameter of the reflector (in %s) ", type);
-			scanf("%lf", &p[i][DIAMETER]);
+		        fgets(str, MAXINPUTLINE-1, stdin);
+			sscanf(str,"%lf", &p[i][DIAMETER]);
 		   }
 		}
 		else /* a director */
 		{
 		   printf("\n\nEnter location of director %d in %s (wrt. reflector at x=0.0) ", i-1, type);
-		   scanf("%lf", &p[i][X]);
+		   fgets(str, MAXINPUTLINE-1, stdin);
+		   sscanf(str,"%lf", &p[i][X]);
 		   if( boom != TRUE)
 		   {
 			printf("Enter the y position of director %d (in %s) ", i-1, type);
-			scanf("%lf", &p[i][Y]);
+		        fgets(str, MAXINPUTLINE-1, stdin);
+			sscanf(str,"%lf", &p[i][Y]);
 		   }
 		   else
 			p[i][Y]=0.0;
 		   printf("Enter the length of director %d (in %s) ", i-1,type);
-		   scanf("%lf", &p[i][LENGTH]);
+		   fgets(str, MAXINPUTLINE-1, stdin);
+		   sscanf(str,"%lf", &p[i][LENGTH]);
 		   if(fixed_diameter == TRUE)
 			p[i][DIAMETER]=diameter;
 		   else
 		   {
 			printf("Enter the diameter of director %d (in %s) ", i-1, type);
-			scanf("%lf", &p[i][DIAMETER]);
+		        fgets(str, MAXINPUTLINE-1, stdin);
+			sscanf(str,"%lf", &p[i][DIAMETER]);
 		   }
 		}
 	}
@@ -200,9 +225,10 @@ int main(int argc, char **argv)
 	fp=fopen(filename,"wt");
 	write_input_data_to_disk(fp, notes, frequency, min_f, max_f, step_f, elements   , driven, parasitic, angular_step, d, p, scale_factor); 
 	fclose(fp);
-	free_string(filename,0L, 1000L);
-	free_string(notes,0L, 1000L);
-	free_string(type,0L, 1000L);
+	free_string(filename,0L, MAXINPUTLINE);
+	free_string(notes,0L, MAXINPUTLINE);
+	free_string(type,0L, MAXINPUTLINE);
+	free_string(str,0L, MAXINPUTLINE);
 	free_dmatrix(d, 1L, (long) driven, 1L, 6L);
 	free_dmatrix(p, 1L, (long) parasitic , 1L, 4L);
 	exit(0);
