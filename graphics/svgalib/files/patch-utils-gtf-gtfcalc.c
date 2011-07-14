--- utils/gtf/gtfcalc.c.orig	1999-07-17 14:13:02.000000000 +0200
+++ utils/gtf/gtfcalc.c	2011-07-01 01:48:14.000000000 +0200
@@ -45,6 +45,7 @@
 #include <string.h>
 #include <ctype.h>
 #include <math.h>
+#include <sys/param.h>
 #include "gtf.h"
 
 /*------------------------- Global Variables ------------------------------*/
@@ -64,10 +65,12 @@
 
 /*-------------------------- Implementation -------------------------------*/
 
+#if __FreeBSD_version < 503000
 static double round(double v)
 {
 	return floor(v + 0.5);
 }
+#endif
 
 static void GetInternalConstants(GTF_constants *c)
 /****************************************************************************
@@ -329,7 +332,7 @@
 
 #ifdef	TESTING_GTF
 
-void main(int argc,char *argv[])
+int main(int argc,char *argv[])
 {
 	FILE		*f;
 	double		xPixels,yPixels,freq;
