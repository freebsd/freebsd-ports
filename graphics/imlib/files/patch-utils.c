--- Imlib/utils.c.orig	2012-04-27 07:12:19.000000000 +0200
+++ Imlib/utils.c	2012-04-27 07:15:39.000000000 +0200
@@ -1899,6 +1899,7 @@
 };
 
 #ifdef HAVE_LIBPNG
+#include "pngpriv.h"
 static void
 _png_io_read(png_structp png_ptr,
 	     png_bytep data, png_uint_32 size)
@@ -1982,7 +1983,7 @@
       return NULL;
     }
   
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
     {
       png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
       return NULL;
