--- php_zookeeper_config_class.c.orig	2019-12-11 01:31:04 UTC
+++ php_zookeeper_config_class.c
@@ -25,6 +25,10 @@
 #include "php_zookeeper_config_class.h"
 #include "php_zookeeper_stat.h"
 
+#if PHP_MAJOR_VERSION >= 8
+#define TSRMLS_CC
+#endif
+
 typedef struct {
     php_zk_t     *php_zk;
     zend_object    zo;
