--- src/libjasper/base/jas_image.c.orig	2007-01-19 22:43:05.000000000 +0100
+++ src/libjasper/base/jas_image.c	2016-02-20 13:59:00.999124000 +0100
@@ -142,7 +142,7 @@
 	image->inmem_ = true;
 
 	/* Allocate memory for the per-component information. */
-	if (!(image->cmpts_ = jas_malloc(image->maxcmpts_ *
+	if (!(image->cmpts_ = jas_malloc2(image->maxcmpts_,
 	  sizeof(jas_image_cmpt_t *)))) {
 		jas_image_destroy(image);
 		return 0;
@@ -426,6 +426,10 @@
 		return -1;
 	}
 
+	if (!data->rows_) {
+		return -1;
+	}
+
 	if (jas_matrix_numrows(data) != height || jas_matrix_numcols(data) != width) {
 		if (jas_matrix_resize(data, height, width)) {
 			return -1;
@@ -479,6 +483,10 @@
 		return -1;
 	}
 
+	if (!data->rows_) {
+		return -1;
+	}
+
 	if (jas_matrix_numrows(data) != height || jas_matrix_numcols(data) != width) {
 		return -1;
 	}
@@ -774,8 +782,7 @@
 	jas_image_cmpt_t **newcmpts;
 	int cmptno;
 
-	newcmpts = (!image->cmpts_) ? jas_malloc(maxcmpts * sizeof(jas_image_cmpt_t *)) :
-	  jas_realloc(image->cmpts_, maxcmpts * sizeof(jas_image_cmpt_t *));
+	newcmpts = jas_realloc2(image->cmpts_, maxcmpts, sizeof(jas_image_cmpt_t *));
 	if (!newcmpts) {
 		return -1;
 	}
