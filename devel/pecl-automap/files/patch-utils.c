--- ./utils.c.orig	2008-01-18 22:07:09.000000000 -0500
+++ ./utils.c	2010-04-12 19:04:13.000000000 -0400
@@ -65,37 +65,37 @@
 /*============================================================================*/
 /* Generic arginfo structures */
 
-static ZEND_BEGIN_ARG_INFO_EX(UT_noarg_arginfo, 0, 0, 0)
+ZEND_BEGIN_ARG_INFO_EX(UT_noarg_arginfo, 0, 0, 0)
 ZEND_END_ARG_INFO()
 
-static ZEND_BEGIN_ARG_INFO_EX(UT_noarg_ref_arginfo, 0, 1, 0)
+ZEND_BEGIN_ARG_INFO_EX(UT_noarg_ref_arginfo, 0, 1, 0)
 ZEND_END_ARG_INFO()
 
-static ZEND_BEGIN_ARG_INFO_EX(UT_1arg_arginfo, 0, 0, 1)
+ZEND_BEGIN_ARG_INFO_EX(UT_1arg_arginfo, 0, 0, 1)
 ZEND_ARG_INFO(0, arg1)
 ZEND_END_ARG_INFO()
 
-static ZEND_BEGIN_ARG_INFO_EX(UT_1arg_ref_arginfo, 0, 1, 1)
+ZEND_BEGIN_ARG_INFO_EX(UT_1arg_ref_arginfo, 0, 1, 1)
 ZEND_ARG_INFO(0, arg1)
 ZEND_END_ARG_INFO()
 
-static ZEND_BEGIN_ARG_INFO_EX(UT_2args_arginfo, 0, 0, 2)
+ZEND_BEGIN_ARG_INFO_EX(UT_2args_arginfo, 0, 0, 2)
 ZEND_ARG_INFO(0, arg1)
 ZEND_ARG_INFO(0, arg2)
 ZEND_END_ARG_INFO()
 
-static ZEND_BEGIN_ARG_INFO_EX(UT_2args_ref_arginfo, 0, 1, 2)
+ZEND_BEGIN_ARG_INFO_EX(UT_2args_ref_arginfo, 0, 1, 2)
 ZEND_ARG_INFO(0, arg1)
 ZEND_ARG_INFO(0, arg2)
 ZEND_END_ARG_INFO()
 
-static ZEND_BEGIN_ARG_INFO_EX(UT_3args_arginfo, 0, 0, 3)
+ZEND_BEGIN_ARG_INFO_EX(UT_3args_arginfo, 0, 0, 3)
 ZEND_ARG_INFO(0, arg1)
 ZEND_ARG_INFO(0, arg2)
 ZEND_ARG_INFO(0, arg3)
 ZEND_END_ARG_INFO()
 
-static ZEND_BEGIN_ARG_INFO_EX(UT_3args_ref_arginfo, 0, 1, 3)
+ZEND_BEGIN_ARG_INFO_EX(UT_3args_ref_arginfo, 0, 1, 3)
 ZEND_ARG_INFO(0, arg1)
 ZEND_ARG_INFO(0, arg2)
 ZEND_ARG_INFO(0, arg3)
@@ -234,13 +234,13 @@
 
 static void ut_persistent_zval_ptr_dtor(zval ** zval_ptr)
 {
-	(*zval_ptr)->refcount--;
-	if ((*zval_ptr)->refcount == 0) {
+	Z_DELREF_P((*zval_ptr));
+	if (Z_REFCOUNT_P((*zval_ptr)) == 0) {
 		ut_persistent_zval_dtor(*zval_ptr);
 		pefree(*zval_ptr, 1);
 	} else {
-		if ((*zval_ptr)->refcount == 1)
-			(*zval_ptr)->is_ref = 0;
+		if (Z_REFCOUNT_P((*zval_ptr)) == 1)
+			Z_UNSET_ISREF_P((*zval_ptr));
 	}
 }
 
