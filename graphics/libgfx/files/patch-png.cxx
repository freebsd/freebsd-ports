--- src/raster-png.cxx.orig	2004-09-27 06:45:31.000000000 +0200
+++ src/raster-png.cxx	2012-05-04 12:59:52.000000000 +0200
@@ -42,7 +42,7 @@
    // Because we didn't set up any error handlers, we need to be
    // prepared to handle longjmps out of the library on error
    // conditions.
-   if( setjmp(png_ptr->jmpbuf) )
+   if( setjmp(png_jmpbuf(png_ptr)) )
    {
       png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
       fclose(fp);
@@ -132,7 +132,7 @@
       return false;
    }
 
-   if( setjmp(png_ptr->jmpbuf) )
+   if( setjmp(png_jmpbuf(png_ptr)) )
    {
       fclose(fp);
       png_destroy_write_struct(&png_ptr,  (png_infopp)NULL);
