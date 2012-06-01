--- tools/quake3/q3map2/image.c.orig	2006-02-10 23:01:20.000000000 +0100
+++ tools/quake3/q3map2/image.c	2012-05-26 20:56:51.000000000 +0200
@@ -35,6 +35,7 @@
 
 /* dependencies */
 #include "q3map2.h"
+#include "pngpriv.h"
 
 
 
@@ -180,7 +181,7 @@
 	png->io_ptr = &pb; /* hack! */
 	
 	/* set error longjmp */
-	if( setjmp( png->jmpbuf ) )
+	if( setjmp( png_jmpbuf(png) ) )
 	{
 		Sys_Printf( "WARNING: An error occurred reading PNG image\n" );
 		png_destroy_read_struct( &png, &info, &end );
