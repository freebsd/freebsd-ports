--- src/libjasper/base/jas_seq.c.orig	2007-01-19 22:43:05.000000000 +0100
+++ src/libjasper/base/jas_seq.c	2013-04-17 22:32:23.000000000 +0200
@@ -114,7 +114,7 @@
 	matrix->datasize_ = numrows * numcols;
 
 	if (matrix->maxrows_ > 0) {
-		if (!(matrix->rows_ = jas_malloc(matrix->maxrows_ *
+		if (!(matrix->rows_ = jas_malloc2(matrix->maxrows_,
 		  sizeof(jas_seqent_t *)))) {
 			jas_matrix_destroy(matrix);
 			return 0;
@@ -122,7 +122,7 @@
 	}
 
 	if (matrix->datasize_ > 0) {
-		if (!(matrix->data_ = jas_malloc(matrix->datasize_ *
+		if (!(matrix->data_ = jas_malloc2(matrix->datasize_,
 		  sizeof(jas_seqent_t)))) {
 			jas_matrix_destroy(matrix);
 			return 0;
@@ -220,7 +220,7 @@
 	mat0->numrows_ = r1 - r0 + 1;
 	mat0->numcols_ = c1 - c0 + 1;
 	mat0->maxrows_ = mat0->numrows_;
-	mat0->rows_ = jas_malloc(mat0->maxrows_ * sizeof(jas_seqent_t *));
+	mat0->rows_ = jas_malloc2(mat0->maxrows_, sizeof(jas_seqent_t *));
 	for (i = 0; i < mat0->numrows_; ++i) {
 		mat0->rows_[i] = mat1->rows_[r0 + i] + c0;
 	}
