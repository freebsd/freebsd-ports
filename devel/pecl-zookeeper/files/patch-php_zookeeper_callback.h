--- php_zookeeper_callback.h.orig	2019-12-11 01:31:04 UTC
+++ php_zookeeper_callback.h
@@ -31,7 +31,11 @@ typedef struct _php_cb_data_t {
 #endif
 } php_cb_data_t;
 
+#if PHP_MAJOR_VERSION >= 8
+php_cb_data_t* php_cb_data_new(HashTable *ht, zend_fcall_info *fci, zend_fcall_info_cache *fcc, zend_bool oneshot);
+#else
 php_cb_data_t* php_cb_data_new(HashTable *ht, zend_fcall_info *fci, zend_fcall_info_cache *fcc, zend_bool oneshot TSRMLS_DC);
+#endif
 void php_cb_data_destroy(php_cb_data_t *cbd);
 void php_cb_data_remove(php_cb_data_t *cb_data);
 
