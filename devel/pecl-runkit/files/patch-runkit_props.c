--- ./runkit_props.c.orig	2006-06-06 17:06:08.000000000 -0400
+++ ./runkit_props.c	2010-04-13 00:04:47.000000000 -0400
@@ -124,8 +124,8 @@
 	ALLOC_ZVAL(copyval);
 	*copyval = *value;
 	zval_copy_ctor(copyval);
-	copyval->refcount = 1;
-	copyval->is_ref = 0;
+	Z_SET_REFCOUNT_P(copyval, 1);
+	Z_UNSET_ISREF_P(copyval);
 
 	if (zend_hash_add(&ce->default_properties, key, key_len + 1, &copyval, sizeof(zval *), NULL) == FAILURE) {
 		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Unable to add default property to class definition");
