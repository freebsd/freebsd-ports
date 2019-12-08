--- php_zookeeper_callback.h.orig	2019-03-08 00:37:59 UTC
+++ php_zookeeper_callback.h
@@ -24,7 +24,7 @@ typedef struct _php_cb_data_t {
     zend_fcall_info fci;
     zend_fcall_info_cache fcc;
     zend_bool oneshot;
-    ulong h;
+    zend_ulong h;
     HashTable *ht;
 #if ZTS
     void ***ctx;
@@ -34,4 +34,4 @@ typedef struct _php_cb_data_t {
 php_cb_data_t* php_cb_data_new(HashTable *ht, zend_fcall_info *fci, zend_fcall_info_cache *fcc, zend_bool oneshot TSRMLS_DC);
 void php_cb_data_destroy(php_cb_data_t **entry);
 
-#endif  /* PHP_ZOOKEEPER_CALLBACK */
\ No newline at end of file
+#endif  /* PHP_ZOOKEEPER_CALLBACK */
