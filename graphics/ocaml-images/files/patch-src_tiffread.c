--- src/tiffread.c.orig	2009-10-26 13:42:03.000000000 +0100
+++ src/tiffread.c	2010-08-28 10:47:42.000000000 +0200
@@ -20,15 +20,21 @@
 #include <caml/alloc.h>
 #include <caml/memory.h>
 #include <caml/fail.h>
+#include "oversized.h"
 
 /* These are defined in caml/config.h */
 #define int16 int16tiff
 #define uint16 uint16tiff
 #define int32 int32tiff
 #define uint32 uint32tiff
+#define int64 int64tiff
+#define uint64 uint64tiff
 
 #include <tiffio.h>
 
+#undef int64
+#undef uint64
+
 extern value *imglib_error;
 
 value open_tiff_file_for_read( name )
@@ -64,6 +70,10 @@
     TIFFGetField(tif, TIFFTAG_YRESOLUTION, &yres);
     TIFFGetField(tif, TIFFTAG_PHOTOMETRIC, &photometric);
 
+    if (oversized (imagewidth, imagelength)) {
+	failwith_oversized("tiff");
+    }
+
     if( imagesample == 3 && photometric == PHOTOMETRIC_RGB ){
       if( imagebits != 8 ){
 	failwith("Sorry, tiff rgb file must be 24bit-color");
