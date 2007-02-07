--- utils/gtf/gtfcalc.c.orig	Tue Jan 23 12:48:50 2007
+++ utils/gtf/gtfcalc.c	Tue Jan 23 12:49:18 2007
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
