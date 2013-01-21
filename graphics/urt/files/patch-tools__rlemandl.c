--- tools/rlemandl.c.orig	1992-01-24 03:31:20.000000000 +0900
+++ tools/rlemandl.c	2012-10-15 22:57:29.000000000 +0900
@@ -12,7 +12,7 @@
 #include <math.h>
 #include "rle.h"
 
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
