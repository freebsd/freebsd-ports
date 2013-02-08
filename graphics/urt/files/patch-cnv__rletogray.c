--- cnv/rletogray.c.orig	1992-04-30 22:59:30.000000000 +0900
+++ cnv/rletogray.c	2012-10-15 22:37:09.000000000 +0900
@@ -30,6 +30,7 @@
 */
 
 #include <stdio.h>
+#include <string.h>
 #include "rle.h"
 
 typedef FILE	*FILPTR;
@@ -41,7 +42,7 @@
  *	infile			File to split.  If none, uses stdin.
  */
 
-void
+int
 main(argc, argv)
 int  argc;
 char *argv[];
