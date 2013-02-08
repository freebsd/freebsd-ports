--- tools/rlenoise.c.orig	1992-01-24 03:31:37.000000000 +0900
+++ tools/rlenoise.c	2012-10-16 00:48:26.000000000 +0900
@@ -20,6 +20,7 @@
  */
 
 #include <stdio.h>
+#include <time.h>
 #include "rle.h"
 
 /* Change this according the value on your system.  This is a crock. */
@@ -27,7 +28,7 @@
 
 #define MALLOC_ERR RLE_CHECK_ALLOC( cmd_name( argv ), 0, 0 )
 
-void
+int
 main( argc, argv )
 int argc;
 char ** argv;
