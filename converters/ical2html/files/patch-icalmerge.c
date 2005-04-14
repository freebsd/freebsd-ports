--- icalmerge.c.orig	Thu Jul 31 07:19:06 2003
+++ icalmerge.c	Wed Apr 13 18:08:16 2005
@@ -27,7 +27,7 @@
 #include "config.h"
 
 
-#define PRODID "-//W3C//NONSGML icalmerge " ## VERSION ## "//EN"
+#define PRODID "-//W3C//NONSGML icalmerge "/**/VERSION/**/"//EN"
 
 #define ERR_OUT_OF_MEM 1	/* Program exit codes */
 #define ERR_USAGE 2
