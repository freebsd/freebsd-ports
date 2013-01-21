--- tools/rlescale.c.orig	1992-01-24 05:37:33.000000000 +0900
+++ tools/rlescale.c	2012-10-15 22:59:09.000000000 +0900
@@ -22,7 +22,7 @@
 #include "rle_raw.h"
 #include <math.h>
 
-void
+int
 main( argc, argv )
 int argc;
 char ** argv;
