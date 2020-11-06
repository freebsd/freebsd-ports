--- php_zookeeper_config_class.h.orig	2019-12-11 01:31:04 UTC
+++ php_zookeeper_config_class.h
@@ -19,7 +19,12 @@
 
 extern zend_class_entry *php_zk_config_ce;
 
+#if PHP_MAJOR_VERSION >= 8
+void php_zk_config_register(void);
+zend_object* php_zk_config_new_from_zk(zend_class_entry *ce, php_zk_t *php_zk);
+#else
 void php_zk_config_register(TSRMLS_D);
 zend_object* php_zk_config_new_from_zk(zend_class_entry *ce, php_zk_t *php_zk TSRMLS_DC);
+#endif
 
 #endif  /* PHP_ZOOKEEPER_CONFIG_CLASS */
