--- tools/quake3/q3map2/image.c.orig	2006-02-10 23:01:20.000000000 +0100
+++ tools/quake3/q3map2/image.c	2012-05-26 20:56:51.000000000 +0200
@@ -177,10 +177,9 @@ static void LoadPNGBuffer( byte *buffer,
 	pb.size = size;
 	pb.offset = 0;
 	png_set_read_fn( png, &pb, PNGReadData );
-	png->io_ptr = &pb; /* hack! */
 	
 	/* set error longjmp */
-	if( setjmp( png->jmpbuf ) )
+	if( setjmp( png_jmpbuf(png) ) )
 	{
 		Sys_Printf( "WARNING: An error occurred reading PNG image\n" );
 		png_destroy_read_struct( &png, &info, &end );
