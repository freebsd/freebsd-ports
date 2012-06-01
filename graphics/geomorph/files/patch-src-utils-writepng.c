--- src/utils/writepng.c.orig	2008-01-23 03:14:22.000000000 +0100
+++ src/utils/writepng.c	2012-05-04 12:28:50.000000000 +0200
@@ -20,6 +20,7 @@
  */
 
 #include <png.h>
+#include <zlib.h>
 #include <stdlib.h>
 #include "./utils.h"
 
@@ -75,7 +76,7 @@
 
    /* Set error handling.    */
 
-   if (setjmp(png_ptr->jmpbuf))
+   if (setjmp(png_jmpbuf(png_ptr)))
    {
       /* If we get here, we had a problem writing the file */
       fclose(fp);
