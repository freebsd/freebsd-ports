--- ext/standard/incomplete_class.c.orig	Fri Oct 14 07:49:19 2005
+++ ext/standard/incomplete_class.c	Fri Oct 14 07:50:12 2005
@@ -122,7 +122,7 @@
 
 /* {{{ php_lookup_class_name
  */
-char *php_lookup_class_name(zval *object, size_t *nlen)
+char *php_lookup_class_name(zval *object, zend_uint *nlen)
 {
 	zval **val;
 	char *retval = NULL;
@@ -144,7 +144,7 @@
 
 /* {{{ php_store_class_name
  */
-void php_store_class_name(zval *object, const char *name, size_t len)
+void php_store_class_name(zval *object, const char *name, zend_uint len)
 {
 	zval *val;
 	TSRMLS_FETCH();
