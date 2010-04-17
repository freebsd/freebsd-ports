--- ./imlib2.c.orig	2004-01-01 18:57:55.000000000 -0500
+++ ./imlib2.c	2010-04-16 20:02:16.000000000 -0400
@@ -47,6 +47,10 @@
 static int le_imlib2_img;
 static int le_imlib2_poly;
 
+ZEND_BEGIN_ARG_INFO(second_arg_force_ref, 0)
+	ZEND_ARG_PASS_INFO(0)
+	ZEND_ARG_PASS_INFO(1)
+	ZEND_END_ARG_INFO();
 
 function_entry imlib2_functions[] = {
 	PHP_FE(imlib2_image_modify_gamma,NULL)
@@ -643,8 +647,8 @@
 	zval **img, **gamma;
 	Imlib_Image im;
 	Imlib_Color_Modifier cm;
-	IMLIB2_LS_FETCH();
 	double ng;
+	IMLIB2_LS_FETCH();
 
 	if (ZEND_NUM_ARGS() != 2 | zend_get_parameters_ex(2, &img, &gamma) == FAILURE) {
 		WRONG_PARAM_COUNT;
@@ -675,8 +679,8 @@
 	zval **img, **contrast;
 	Imlib_Image im;
 	Imlib_Color_Modifier cm;
-	IMLIB2_LS_FETCH();
 	double nc;
+	IMLIB2_LS_FETCH();
 
 	if (ZEND_NUM_ARGS() != 2 | zend_get_parameters_ex(2, &img, &contrast) == FAILURE) {
 		WRONG_PARAM_COUNT;
@@ -707,8 +711,8 @@
 	zval **img, **bv;
 	Imlib_Image im;
 	Imlib_Color_Modifier cm;
-	IMLIB2_LS_FETCH();
 	double nbv;
+	IMLIB2_LS_FETCH();
 
 	if (ZEND_NUM_ARGS() != 2 | zend_get_parameters_ex(2, &img, &bv) == FAILURE) {
 		WRONG_PARAM_COUNT;
@@ -760,9 +764,9 @@
 {
 	zval **img, **angle;
 	double rot_angle, rads, pi;
-	pi = 3.141592653;
 	Imlib_Image src_img, dst_img;
 	IMLIB2_LS_FETCH();
+	pi = 3.141592653;
 
 	if((ZEND_NUM_ARGS() != 2) || zend_get_parameters_ex(2, &img, &angle) == FAILURE) {
 		WRONG_PARAM_COUNT;
