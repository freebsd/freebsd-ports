--- utilssdl/PNG.cpp.orig	2004-12-18 03:41:42.000000000 +0100
+++ utilssdl/PNG.cpp	2012-05-08 07:00:15.000000000 +0200
@@ -45,7 +45,7 @@
 {
     png_size_t check;
 
-    check = fwrite( data, 1, length, (FILE *)(png->io_ptr));
+    check = fwrite( data, 1, length, (FILE *)(png_get_io_ptr(png)));
     if( check != length)
     {
 	png_error( png, "Write Error");
@@ -72,7 +72,7 @@
 	return false;
     }
 
-    if( setjmp(_png->jmpbuf))
+    if( setjmp(png_jmpbuf(_png)))
     {
 	fclose( fp);
 	png_destroy_write_struct(&_png, (png_infopp)NULL);
