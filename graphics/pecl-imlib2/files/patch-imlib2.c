--- imlib2.c.orig	Wed Sep 20 10:05:27 2006
+++ imlib2.c	Wed Sep 20 10:06:15 2006
@@ -643,8 +643,8 @@
 	zval **img, **gamma;
 	Imlib_Image im;
 	Imlib_Color_Modifier cm;
-	IMLIB2_LS_FETCH();
 	double ng;
+	IMLIB2_LS_FETCH();
 
 	if (ZEND_NUM_ARGS() != 2 | zend_get_parameters_ex(2, &img, &gamma) == FAILURE) {
 		WRONG_PARAM_COUNT;
@@ -675,8 +675,8 @@
 	zval **img, **contrast;
 	Imlib_Image im;
 	Imlib_Color_Modifier cm;
-	IMLIB2_LS_FETCH();
 	double nc;
+	IMLIB2_LS_FETCH();
 
 	if (ZEND_NUM_ARGS() != 2 | zend_get_parameters_ex(2, &img, &contrast) == FAILURE) {
 		WRONG_PARAM_COUNT;
@@ -707,8 +707,8 @@
 	zval **img, **bv;
 	Imlib_Image im;
 	Imlib_Color_Modifier cm;
-	IMLIB2_LS_FETCH();
 	double nbv;
+	IMLIB2_LS_FETCH();
 
 	if (ZEND_NUM_ARGS() != 2 | zend_get_parameters_ex(2, &img, &bv) == FAILURE) {
 		WRONG_PARAM_COUNT;
@@ -760,9 +760,9 @@
 {
 	zval **img, **angle;
 	double rot_angle, rads, pi;
-	pi = 3.141592653;
 	Imlib_Image src_img, dst_img;
 	IMLIB2_LS_FETCH();
+	pi = 3.141592653;
 
 	if((ZEND_NUM_ARGS() != 2) || zend_get_parameters_ex(2, &img, &angle) == FAILURE) {
 		WRONG_PARAM_COUNT;
