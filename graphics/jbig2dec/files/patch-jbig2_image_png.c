--- jbig2_image_png.c.orig	2014-10-31 13:30:04 UTC
+++ jbig2_image_png.c
@@ -26,7 +26,6 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <png.h>
-#include <pngstruct.h>
 #define CVT_PTR(ptr) (ptr)
 
 #include "jbig2.h"
@@ -40,7 +39,7 @@ jbig2_png_write_data(png_structp png_ptr
 {
     png_size_t check;
 
-    check = fwrite(data, 1, length, (png_FILE_p)png_ptr->io_ptr);
+    check = fwrite(data, 1, length, (png_FILE_p)png_get_io_ptr(png_ptr));
     if (check != length) {
       png_error(png_ptr, "Write Error");
     }
@@ -50,7 +49,7 @@ static void
 jbig2_png_flush(png_structp png_ptr)
 {
     png_FILE_p io_ptr;
-    io_ptr = (png_FILE_p)CVT_PTR((png_ptr->io_ptr));
+    io_ptr = (png_FILE_p)png_get_io_ptr(png_ptr);
     if (io_ptr != NULL)
         fflush(io_ptr);
 }
