--- editss.c.orig	Wed Mar 22 19:39:59 2000
+++ editss.c	Thu Oct 10 14:39:00 2002
@@ -28,7 +28,6 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <values.h>
 #include <string.h>
 #include <fcntl.h>
 #include <time.h>
@@ -509,7 +508,7 @@
 	while (getoneshipdef(a,fin)) {
 		nrships+=1;	
 	}		   
-	fclose(fin);
+	if (fin!=NULL) fclose(fin);
 	if (nrships<1) i1=1; else i1=nrships;
 
 	a[0]='\0';
