--- tools/rlegrid.c.orig	1992-04-30 23:12:02.000000000 +0900
+++ tools/rlegrid.c	2012-10-15 22:55:35.000000000 +0900
@@ -51,7 +51,7 @@
  *	[None]
  * Algorithm:
  */
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
@@ -65,7 +65,7 @@
     rle_op **scanraw[2];	/* space for two raw scanline buffers */
     rle_op *p, *q;
     int    *nrawp[2];
-    unsigned char fg, bg;
+    unsigned char fg;
 
     out_hdr = *rle_hdr_init( NULL );
 
@@ -81,7 +81,6 @@
        exit( 1 );
 
     fg = fg_color;
-    bg = bg_color;
 
     outfile = rle_open_f( cmd_name( argv ), outfname, "w" );
     
