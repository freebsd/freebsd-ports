--- src/tiffread.c.orig	2011-06-22 20:04:32.000000000 +0200
+++ src/tiffread.c
@@ -23,14 +23,22 @@
 
 #include "oversized.h"
 
+/* Avoid redefinitions */
+#undef int16
+#undef uint16
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
@@ -70,6 +78,10 @@
       failwith_oversized("tiff");
     }
 
+    if (oversized (imagewidth, imagelength)) {
+	failwith_oversized("tiff");
+    }
+
     if( imagesample == 3 && photometric == PHOTOMETRIC_RGB ){
       if( imagebits != 8 ){
 	failwith("Sorry, tiff rgb file must be 24bit-color");
