--- php_zookeeper_callback.c.orig	2019-12-11 01:31:04 UTC
+++ php_zookeeper_callback.c
@@ -19,6 +19,10 @@
 
 #include "php_zookeeper_callback.h"
 
+#if PHP_MAJOR_VERSION >= 8
+#define TSRMLS_DC
+#endif
+
 php_cb_data_t* php_cb_data_new(HashTable *ht, zend_fcall_info *fci, zend_fcall_info_cache *fcc, zend_bool oneshot TSRMLS_DC)
 {
     php_cb_data_t *cbd = ecalloc(1, sizeof(php_cb_data_t));
