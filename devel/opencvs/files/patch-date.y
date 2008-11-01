--- date.y	16 Feb 2008 01:00:00 -0000	1.18
+++ date.y	17 Oct 2008 08:51:45 -0000
@@ -14,6 +14,7 @@
 /* SUPPRESS 287 on yaccpar_sccsid *//* Unused static variable */
 /* SUPPRESS 288 on yyerrlab *//* Label unused */
 
+#include <time.h>
 #include <sys/timeb.h>
 
 #include <ctype.h>

