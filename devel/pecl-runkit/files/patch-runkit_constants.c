--- ./runkit_constants.c.orig	2006-06-06 17:06:08.000000000 -0400
+++ ./runkit_constants.c	2010-04-13 00:06:11.000000000 -0400
@@ -197,8 +197,8 @@
 	ALLOC_ZVAL(copyval);
 	*copyval = *value;
 	zval_copy_ctor(copyval);
-	copyval->refcount = 1;
-	copyval->is_ref = 0;
+	Z_SET_REFCOUNT_P(copyval, 1);
+	Z_UNSET_ISREF_P(copyval);
 	if (zend_hash_add(&ce->constants_table, constname, constname_len + 1, &copyval, sizeof(zval *), NULL) == FAILURE) {
 		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Unable to add constant to class definition");
 		zval_ptr_dtor(&copyval);
