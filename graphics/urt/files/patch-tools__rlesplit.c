--- tools/rlesplit.c.orig	1992-11-10 05:33:51.000000000 +0900
+++ tools/rlesplit.c	2012-10-16 00:51:06.000000000 +0900
@@ -15,6 +15,7 @@
 */
 
 #include <stdio.h>
+#include <string.h>
 #include "rle.h"
 #include "rle_raw.h"
 
@@ -56,7 +57,7 @@
  *	[None]
  */
 
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
