--- src/raster-png.cxx.orig	2004-09-27 04:45:31 UTC
+++ src/raster-png.cxx
@@ -9,6 +9,7 @@
 
  ************************************************************************/
 
+#include <cstring>
 #include <vector>
 #include <gfx/gfx.h>
 #include <gfx/raster.h>
@@ -42,7 +43,7 @@ ByteRaster *read_png_image(const char *f
    // Because we didn't set up any error handlers, we need to be
    // prepared to handle longjmps out of the library on error
    // conditions.
-   if( setjmp(png_ptr->jmpbuf) )
+   if( setjmp(png_jmpbuf(png_ptr)) )
    {
       png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
       fclose(fp);
@@ -132,7 +133,7 @@ bool write_png_image(const char *file_na
       return false;
    }
 
-   if( setjmp(png_ptr->jmpbuf) )
+   if( setjmp(png_jmpbuf(png_ptr)) )
    {
       fclose(fp);
       png_destroy_write_struct(&png_ptr,  (png_infopp)NULL);
