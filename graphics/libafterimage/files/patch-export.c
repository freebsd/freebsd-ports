--- export.c.orig	2011-01-15 06:52:22.000000000 +0100
+++ export.c	2012-05-04 12:57:15.000000000 +0200
@@ -496,7 +496,7 @@
 	png_ptr = png_create_write_struct( PNG_LIBPNG_VER_STRING, NULL, NULL, NULL );
     if ( png_ptr != NULL )
     	if( (info_ptr = png_create_info_struct(png_ptr)) != NULL )
-			if( setjmp(png_ptr->jmpbuf) )
+			if( setjmp(png_jmpbuf(png_ptr)) )
 			{
 				png_destroy_info_struct(png_ptr, (png_infopp) &info_ptr);
 				info_ptr = NULL ;
