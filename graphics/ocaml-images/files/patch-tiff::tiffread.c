--- tiff/tiffread.c.orig	Tue Sep 21 23:56:44 2004
+++ tiff/tiffread.c	Mon Dec  5 09:25:43 2005
@@ -28,11 +28,6 @@
 
 #include <tiffio.h>
 
-#undef int16
-#undef uint16
-#undef int32
-#undef uint32
-
 extern value *imglib_error;
 
 value open_tiff_file_for_read( name )
