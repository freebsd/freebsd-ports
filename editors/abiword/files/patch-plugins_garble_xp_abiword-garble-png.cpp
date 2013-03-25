--- plugins/garble/xp/abiword-garble-png.cpp.orig	2013-03-25 06:55:41.000000000 +0000
+++ plugins/garble/xp/abiword-garble-png.cpp	2013-03-25 06:56:20.000000000 +0000
@@ -79,7 +79,7 @@
 		png_set_strip_alpha( png_ptr );
 		png_set_interlace_handling( png_ptr );
 		png_set_bgr( png_ptr );
-		rowbytes = info_ptr->rowbytes;
+		rowbytes = png_get_rowbytes(png_ptr, info_ptr);
 		png_destroy_read_struct( &png_ptr, &info_ptr, NULL );
 	}
 
