--- tools/rlepatch.c.orig	Thu Mar 10 21:17:33 2005
+++ tools/rlepatch.c	Thu Mar 10 21:18:56 2005
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
