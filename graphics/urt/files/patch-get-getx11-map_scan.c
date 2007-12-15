--- get/getx11/map_scan.c.orig	Thu Nov 29 22:24:53 2007
+++ get/getx11/map_scan.c	Thu Nov 29 22:26:37 2007
@@ -2195,7 +2195,7 @@
     
     if (!img->divN || !img->modN || !img->dm16 )
     {
-	fprintf( stderr, "%s: malloc error getting dither arrays\n");
+	fprintf( stderr, "%s: malloc error getting dither arrays\n", progname);
 	exit (1);
     }
 }
