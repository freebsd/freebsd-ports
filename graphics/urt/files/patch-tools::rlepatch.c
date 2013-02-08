--- tools/rlepatch.c.orig	1992-01-24 03:33:19.000000000 +0900
+++ tools/rlepatch.c	2012-10-15 22:58:01.000000000 +0900
@@ -33,7 +33,7 @@
 
 #define IN_WINDOW(y,wind) ((y >= wind.ymin) && (y <= wind.ymax))
 
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
@@ -46,7 +46,7 @@
     rle_pixel ** im_rows, **patch_rows, ** outrows;
     int stdin_used = 0;
     int patches = 0, oflag = 0, i, y, c, xlen, width;
-    int rle_cnt, rle_err;
+    int rle_cnt;
 
     im_hdr = *rle_hdr_init( NULL );
     out_hdr = *rle_hdr_init( NULL );
@@ -86,7 +86,7 @@
     }
 
     for ( rle_cnt = 0;
-	  (rle_err = rle_get_setup( &im_hdr )) == RLE_SUCCESS;
+	  rle_get_setup( &im_hdr ) == RLE_SUCCESS;
 	  rle_cnt++ )
     {
 	/* Get the patch files set up */
