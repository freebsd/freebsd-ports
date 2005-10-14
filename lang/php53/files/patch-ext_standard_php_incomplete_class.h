--- ext/standard/php_incomplete_class.h.orig	Fri Oct 14 07:50:22 2005
+++ ext/standard/php_incomplete_class.h	Fri Oct 14 07:50:59 2005
@@ -42,7 +42,7 @@
 
 #define PHP_CLASS_ATTRIBUTES											\
 	char *class_name;													\
-	size_t name_len;													\
+	zend_uint name_len;													\
 	zend_bool free_class_name = 0;										\
 	zend_bool incomplete_class = 0
 
@@ -55,8 +55,8 @@
 	
 zend_class_entry *php_create_incomplete_class(TSRMLS_D);
 
-char *php_lookup_class_name(zval *object, size_t *nlen);
-void  php_store_class_name(zval *object, const char *name, size_t len);
+char *php_lookup_class_name(zval *object, zend_uint *nlen);
+void  php_store_class_name(zval *object, const char *name, zend_uint len);
 
 #ifdef __cplusplus
 };
