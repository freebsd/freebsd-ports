--- ext/standard/php_var.h.orig	2004/09/05 16:29:04
+++ ext/standard/php_var.h	2005/01/15 18:18:08
@@ -41,6 +41,7 @@ PHPAPI void php_debug_zval_dump(zval **s

 struct php_unserialize_data {
 	void *first;
+	void *first_dtor;
 };

 typedef struct php_unserialize_data php_unserialize_data_t;
@@ -54,7 +55,8 @@ PHPAPI int php_var_unserialize(zval **rv
    zend_hash_destroy(&(var_hash))

 #define PHP_VAR_UNSERIALIZE_INIT(var_hash) \
-	(var_hash).first = 0
+	(var_hash).first = 0; \
+	(var_hash).first_dtor = 0
 #define PHP_VAR_UNSERIALIZE_DESTROY(var_hash) \
 	var_destroy(&(var_hash))

