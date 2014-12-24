--- utilssdl/PNG.cpp.orig	2003-03-03 02:32:18 UTC
+++ utilssdl/PNG.cpp
@@ -45,7 +45,7 @@ void PNG::writeData( png_structp png, pn
 {
     png_uint_32 check;
 
-    check = fwrite( data, 1, length, (FILE *)(png->io_ptr));
+    check = fwrite( data, 1, length, (FILE *)(png_get_io_ptr(png)));
     if( check != length)
     {
 	png_error( png, "Write Error");
@@ -72,7 +72,7 @@ bool PNG::init( FILE *fp, int width, int
 	return false;
     }
 
-    if( setjmp(_png->jmpbuf))
+    if( setjmp(png_jmpbuf(_png)))
     {
 	fclose( fp);
 	png_destroy_write_struct(&_png, (png_infopp)NULL);
