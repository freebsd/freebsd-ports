--- tools/rlegrid.c.orig	Thu Mar 10 21:01:59 2005
+++ tools/rlegrid.c	Thu Mar 10 21:03:02 2005
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
     
