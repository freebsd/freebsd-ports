--- get/getx11/in_cmap.c.orig	Thu Apr 30 23:17:16 1992
+++ get/getx11/in_cmap.c	Fri Dec 27 23:02:36 2002
@@ -70,10 +70,10 @@
     if ( img->sep_colors ||
 	 (img->img_channels == 1 && img->ncmap == 3 && img->cmlen) )
 	/* If using color map directly, apply display gamma, too. */
-	img->in_cmap = buildmap( img_hdr, 3, img->gamma,
+	img->in_cmap = buildmap( img_hdr, 3, (double) img->gamma,
 				 display_gamma );
     else
-	img->in_cmap = buildmap( img_hdr, 3, img->gamma, 1.0 );
+	img->in_cmap = buildmap( img_hdr, 3, (double) img->gamma, 1.0 );
     
     for (i = 0; i < 3; i++ ) {
 	for (j = 0; j < 256; j++)
