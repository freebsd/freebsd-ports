--- utilssdl/PNG.cpp.orig	2010-10-17 01:09:50 UTC
+++ utilssdl/PNG.cpp
@@ -56,7 +56,7 @@ void PNG::writeData( png_structp png, png_bytep data, 
 {
     png_size_t check;
 
-    check = fwrite( data, 1, length, (FILE *)(png->io_ptr));
+    check = fwrite( data, 1, length, (FILE *)(png_get_io_ptr(png)));
     if( check != length)
     {
 	png_error( png, "Write Error");
@@ -83,7 +83,7 @@ bool PNG::init( FILE *fp, int width, int height)
 	return false;
     }
 
-    if( setjmp(_png->jmpbuf))
+    if( setjmp(png_jmpbuf(_png)))
     {
 	fclose( fp);
 	png_destroy_write_struct(&_png, (png_infopp)NULL);
