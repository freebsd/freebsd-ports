--- interfaces/IDirectFBImageProvider/idirectfbimageprovider_png.c.orig	2011-05-05 20:00:29.000000000 +0200
+++ interfaces/IDirectFBImageProvider/idirectfbimageprovider_png.c	2012-05-01 09:15:37.000000000 +0200
@@ -33,6 +33,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <png.h>
+#include <pngpriv.h>
 #include <string.h>
 #include <stdarg.h>
 
@@ -207,7 +207,7 @@
      if (!data->png_ptr)
           goto error;
 
-     if (setjmp( data->png_ptr->jmpbuf )) {
+     if (setjmp( png_jmpbuf(data->png_ptr))) {
           D_ERROR( "ImageProvider/PNG: Error reading header!\n" );
           goto error;
      }
@@ -292,7 +292,7 @@
           rect = dst_data->area.wanted;
      }
 
-     if (setjmp( data->png_ptr->jmpbuf )) {
+     if (setjmp( png_jmpbuf(data->png_ptr))) {
           D_ERROR( "ImageProvider/PNG: Error during decoding!\n" );
 
           if (data->stage < STAGE_IMAGE)
