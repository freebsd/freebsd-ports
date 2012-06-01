--- src/OpenPNG.cpp.orig	2002-12-26 02:52:21.000000000 +0100
+++ src/OpenPNG.cpp	2012-04-30 21:33:15.000000000 +0200
@@ -6,6 +6,7 @@
 
 
 #include <png.h>
+#include <pngpriv.h>
 #include "Debug.h"
 #include "Open.h"
 #include "SimpleImage.h"
@@ -39,7 +40,7 @@
   void PNG_error_function(png_structp png_ptr, png_const_charp warning) {
     // copied from libpng's pngerror.cpp, but without the fprintf
     jmp_buf jmpbuf;
-    memcpy(jmpbuf, png_ptr->jmpbuf, sizeof(jmp_buf));
+    memcpy(jmpbuf, png_ptr->longjmp_buffer, sizeof(jmp_buf));
     longjmp(jmpbuf, 1);
   }
 
