--- get/getfb.c.orig	Mon Mar  7 23:33:32 2005
+++ get/getfb.c	Mon Mar  7 23:44:28 2005
@@ -47,7 +47,7 @@
 	}
 
 	rle_file = argv[0];
-	rle_names( &hdr, hdr.cmd, rle_file );
+	rle_names( &hdr, hdr.cmd, rle_file, 0 );
         hdr.rle_file = rle_open_f(hdr.cmd, rle_file, "r");
 	if( rle_get_setup( &hdr ) < 0 )  {
 		fprintf(stderr, "getfb: Error reading setup information\n");
