--- src/php_tarantool.h.orig	2020-06-29 22:41:13 UTC
+++ src/php_tarantool.h
@@ -180,7 +180,11 @@ PHP_TARANTOOL_API zend_class_entry *php_tarantool_get_
 PHP_TARANTOOL_API zend_class_entry *php_tarantool_get_ioexception(void);
 PHP_TARANTOOL_API zend_class_entry *php_tarantool_get_clienterror(void);
 PHP_TARANTOOL_API zend_class_entry *php_tarantool_get_parsingexception(void);
+#if PHP_MAJOR_VERSION >= 8
+PHP_TARANTOOL_API zend_class_entry *php_tarantool_get_exception_base(int root);
+#else
 PHP_TARANTOOL_API zend_class_entry *php_tarantool_get_exception_base(int root TSRMLS_DC);
+#endif
 
 #ifdef ZTS
 #  define TARANTOOL_G(v) TSRMG(tarantool_globals_id, zend_tarantool_globals *, v)
