--- php_zookeeper_exceptions.c.orig	2019-12-11 01:31:04 UTC
+++ php_zookeeper_exceptions.c
@@ -26,6 +26,13 @@
 
 #include <Zend/zend_exceptions.h>
 
+#if PHP_MAJOR_VERSION >= 8
+#define TSRMLS_C
+#define TSRMLS_CC
+#define TSRMLS_D void
+#define TSRMLS_DC
+#endif
+
 static zend_class_entry *zk_base_exception;
 static zend_class_entry *zk_optimeout_exception;
 static zend_class_entry *zk_connection_exception;
