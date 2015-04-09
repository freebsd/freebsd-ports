--- imlib2.c	2004-01-01 18:57:55.000000000 -0500
+++ imlib2.c	2015-04-09 12:48:55.000000000 -0400
@@ -26,6 +26,7 @@
 
 #include "php.h"
 #include "php_ini.h"
+#include "ext/standard/head.h"
 #include "ext/standard/info.h"
 #include "php_imlib2.h"
 #include <Imlib2.h>
@@ -47,8 +48,12 @@
 static int le_imlib2_img;
 static int le_imlib2_poly;
 
+ZEND_BEGIN_ARG_INFO(second_arg_force_ref, 0)
+	ZEND_ARG_PASS_INFO(0)
+	ZEND_ARG_PASS_INFO(1)
+	ZEND_END_ARG_INFO();
 
-function_entry imlib2_functions[] = {
+zend_function_entry imlib2_functions[] = {
 	PHP_FE(imlib2_image_modify_gamma,NULL)
 	PHP_FE(imlib2_image_modify_contrast,NULL)
 	PHP_FE(imlib2_image_modify_brightness,NULL)
@@ -271,8 +276,8 @@
    *four = Z_LVAL_PP(zfour);
 }
 
-static int _php_handle_cliprect_array(zval **dbox, char *func_name,
-                                      int *x, int *y, int *w, int *h)
+static int _php_handle_cliprect_array(zval **dbox, const char *func_name,
+                                      int *x, int *y, int *w, int *h TSRMLS_DC)
 {
    zval **element, ***box_coords;
    int i,arrcount;
@@ -382,7 +387,7 @@
 }
 
 
-static void _php_imlib2_draw_something(INTERNAL_FUNCTION_PARAMETERS, void (*func)(), char *func_name)
+static void _php_imlib2_draw_something(INTERNAL_FUNCTION_PARAMETERS, void (*func)(), const char *func_name)
 {
    zval **img, **d1, **d2, **d3, **d4, **dr, **dg, **db, **da, **dbox;
    int x,y,w,h,r,g,b,a,cx,cy,cw,ch,argc;
@@ -407,7 +412,7 @@
 
    if (argc > 9)
    {
-      if (!_php_handle_cliprect_array(dbox, func_name, &cx,&cy,&cw,&ch))
+      if (!_php_handle_cliprect_array(dbox, func_name, &cx,&cy,&cw,&ch TSRMLS_CC))
          RETURN_FALSE;
       imlib_context_set_cliprect(cx,cy,cw,ch);
    }
@@ -643,8 +648,8 @@
 	zval **img, **gamma;
 	Imlib_Image im;
 	Imlib_Color_Modifier cm;
-	IMLIB2_LS_FETCH();
 	double ng;
+	IMLIB2_LS_FETCH();
 
 	if (ZEND_NUM_ARGS() != 2 | zend_get_parameters_ex(2, &img, &gamma) == FAILURE) {
 		WRONG_PARAM_COUNT;
@@ -654,7 +659,7 @@
 
 	ng = Z_DVAL_PP(gamma);
 
-	if(cm = imlib_create_color_modifier()){
+	if ((cm = imlib_create_color_modifier())) {
 		imlib_context_set_color_modifier(cm);
 		imlib_context_set_image(im);
 		imlib_modify_color_modifier_gamma(ng);
@@ -675,8 +680,8 @@
 	zval **img, **contrast;
 	Imlib_Image im;
 	Imlib_Color_Modifier cm;
-	IMLIB2_LS_FETCH();
 	double nc;
+	IMLIB2_LS_FETCH();
 
 	if (ZEND_NUM_ARGS() != 2 | zend_get_parameters_ex(2, &img, &contrast) == FAILURE) {
 		WRONG_PARAM_COUNT;
@@ -686,7 +691,7 @@
 
 	nc = Z_DVAL_PP(contrast);
 
-	if(cm = imlib_create_color_modifier()){
+	if ((cm = imlib_create_color_modifier())) {
 		imlib_context_set_color_modifier(cm);
 		imlib_context_set_image(im);
 		imlib_modify_color_modifier_contrast(nc);
@@ -707,8 +712,8 @@
 	zval **img, **bv;
 	Imlib_Image im;
 	Imlib_Color_Modifier cm;
-	IMLIB2_LS_FETCH();
 	double nbv;
+	IMLIB2_LS_FETCH();
 
 	if (ZEND_NUM_ARGS() != 2 | zend_get_parameters_ex(2, &img, &bv) == FAILURE) {
 		WRONG_PARAM_COUNT;
@@ -718,7 +723,7 @@
 
 	nbv = Z_DVAL_PP(bv);
 
-	if(cm = imlib_create_color_modifier()){
+	if ((cm = imlib_create_color_modifier())) {
 		imlib_context_set_color_modifier(cm);
 		imlib_context_set_image(im);
 		imlib_modify_color_modifier_brightness(nbv);
@@ -760,9 +765,9 @@
 {
 	zval **img, **angle;
 	double rot_angle, rads, pi;
-	pi = 3.141592653;
 	Imlib_Image src_img, dst_img;
 	IMLIB2_LS_FETCH();
+	pi = 3.141592653;
 
 	if((ZEND_NUM_ARGS() != 2) || zend_get_parameters_ex(2, &img, &angle) == FAILURE) {
 		WRONG_PARAM_COUNT;
@@ -806,7 +811,7 @@
    tmpfile = estrdup("/tmp/phpimlib.XXXXXX");
 
    if ((fd = mkstemp(tmpfile)) < 0) {
-      php_error(E_WARNING, "%s: unable to open temporary file", get_active_function_name());
+      php_error(E_WARNING, "%s: unable to open temporary file", get_active_function_name(TSRMLS_C));
       efree(tmpfile);
       RETURN_FALSE;
    }
@@ -814,7 +819,7 @@
    /* TODO: notify in case of errors? */
    retval = fchmod(fd, S_IRUSR|S_IWUSR);
    if (retval != 0) {
-      php_error(E_WARNING, "%s: could not change permissions on temporary file", get_active_function_name());
+      php_error(E_WARNING, "%s: could not change permissions on temporary file", get_active_function_name(TSRMLS_C));
       close(fd);
       efree(tmpfile);
       RETURN_FALSE;
@@ -851,7 +856,7 @@
    /* fseek or something, then read the file and dump it out. */
    lseek(fd, 0, SEEK_SET);
 
-   output = php_header();
+   output = php_header(TSRMLS_C);
    if (output) {
       char buf[4096];
 
@@ -861,7 +866,7 @@
       ap_bsetflag(php3_rqst->connection->client, B_EBCDIC2ASCII, 0);
 #endif
       while ((retval = read(fd, buf, sizeof(buf))) > 0) {
-         php_write(buf, retval);
+         php_write(buf, retval TSRMLS_CC);
       }
    }
 
@@ -1254,7 +1259,7 @@
 
    if (argc > 7)
    {
-      if (!_php_handle_cliprect_array(dbox, "imlib_image_draw_polygon", &cx, &cy, &cw, &ch))
+      if (!_php_handle_cliprect_array(dbox, "imlib_image_draw_polygon", &cx, &cy, &cw, &ch TSRMLS_CC))
          RETURN_FALSE;
       imlib_context_set_cliprect(cx,cy,cw,ch);
    }
@@ -1303,7 +1308,7 @@
 
    if (argc > 7)
    {
-      if (!_php_handle_cliprect_array(fbox, "imlib_image_fill_color_range_rectangle", &cx,&cy,&cw,&ch))
+      if (!_php_handle_cliprect_array(fbox, "imlib_image_fill_color_range_rectangle", &cx,&cy,&cw,&ch TSRMLS_CC))
          RETURN_FALSE;
       imlib_context_set_cliprect(cx,cy,cw,ch);
    }
@@ -1350,7 +1355,7 @@
 
    if (argc > 6)
    {
-      if (!_php_handle_cliprect_array(dbox, "imlib_image_fill_polygon", &cx, &cy, &cw, &ch))
+      if (!_php_handle_cliprect_array(dbox, "imlib_image_fill_polygon", &cx, &cy, &cw, &ch TSRMLS_CC))
          RETURN_FALSE;
       imlib_context_set_cliprect(cx,cy,cw,ch);
    }
