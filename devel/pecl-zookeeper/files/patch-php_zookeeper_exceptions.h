--- php_zookeeper_exceptions.h.orig	2019-12-11 01:31:04 UTC
+++ php_zookeeper_exceptions.h
@@ -21,12 +21,21 @@
 /**
  * register exceptions
  */
+#if PHP_MAJOR_VERSION >= 8
+void php_zk_register_exceptions(void);
+zend_class_entry * php_zk_get_exception_with_message(zend_class_entry *ce, char *message);
+#else
 void php_zk_register_exceptions(TSRMLS_D);
 zend_class_entry * php_zk_get_exception_with_message(zend_class_entry *ce, char *message TSRMLS_DC);
+#endif
 /**
  * throw exception according to status
  */
+#if PHP_MAJOR_VERSION >= 8
+void php_zk_throw_exception(int zk_status);
+#else
 void php_zk_throw_exception(int zk_status TSRMLS_DC);
+#endif
 
 #define PHPZK_INITIALIZATION_FAILURE 5999
 #define PHPZK_CONNECT_NOT_CALLED 5998
