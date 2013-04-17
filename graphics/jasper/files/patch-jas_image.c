--- src/libjasper/base/jas_image.c.orig	2007-01-19 22:43:05.000000000 +0100
+++ src/libjasper/base/jas_image.c	2013-04-17 22:32:23.000000000 +0200
@@ -142,7 +142,7 @@
 	image->inmem_ = true;
 
 	/* Allocate memory for the per-component information. */
-	if (!(image->cmpts_ = jas_malloc(image->maxcmpts_ *
+	if (!(image->cmpts_ = jas_malloc2(image->maxcmpts_,
 	  sizeof(jas_image_cmpt_t *)))) {
 		jas_image_destroy(image);
 		return 0;
@@ -774,8 +774,7 @@
 	jas_image_cmpt_t **newcmpts;
 	int cmptno;
 
-	newcmpts = (!image->cmpts_) ? jas_malloc(maxcmpts * sizeof(jas_image_cmpt_t *)) :
-	  jas_realloc(image->cmpts_, maxcmpts * sizeof(jas_image_cmpt_t *));
+	newcmpts = jas_realloc2(image->cmpts_, maxcmpts, sizeof(jas_image_cmpt_t *));
 	if (!newcmpts) {
 		return -1;
 	}
