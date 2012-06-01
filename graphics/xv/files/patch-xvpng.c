--- xvpng.c.orig	2007-05-14 02:53:28.000000000 +0200
+++ xvpng.c	2012-04-27 07:51:56.000000000 +0200
@@ -32,6 +32,8 @@
 #ifdef HAVE_PNG
 
 #include "png.h"
+#include "zlib.h"
+#include "pngpriv.h"
 
 /*** Stuff for PNG Dialog box ***/
 #define PWIDE 318
@@ -458,7 +460,7 @@
     FatalError(software);
   }
 
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     png_destroy_write_struct(&png_ptr, &info_ptr);
     return -1;
   }
@@ -921,7 +923,7 @@
     FatalError("malloc failure in LoadPNG");
   }
 
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     fclose(fp);
     png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
     if (!read_anything) {
@@ -1143,7 +1145,7 @@
 {
   SetISTR(ISTR_WARNING,"%s:  libpng error: %s", fbasename, message);
 
-  longjmp(png_ptr->jmpbuf, 1);
+  longjmp(png_jmpbuf(png_ptr), 1);
 }
 
 
