--- src/tiffread.c.orig	2010-03-26 01:20:08.000000000 -0700
+++ src/tiffread.c	2010-03-26 01:20:46.000000000 -0700
@@ -20,6 +20,7 @@
 #include <caml/alloc.h>
 #include <caml/memory.h>
 #include <caml/fail.h>
+#include "oversized.h"
 
 /* These are defined in caml/config.h */
 #define int16 int16tiff
@@ -64,6 +65,10 @@
     TIFFGetField(tif, TIFFTAG_YRESOLUTION, &yres);
     TIFFGetField(tif, TIFFTAG_PHOTOMETRIC, &photometric);
 
+    if (oversized (imagewidth, imagelength)) {
+	failwith_oversized("tiff");
+    }
+
     if( imagesample == 3 && photometric == PHOTOMETRIC_RGB ){
       if( imagebits != 8 ){
 	failwith("Sorry, tiff rgb file must be 24bit-color");
