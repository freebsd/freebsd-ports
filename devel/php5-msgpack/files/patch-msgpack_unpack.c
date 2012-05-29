--- ./msgpack_unpack.c.orig	2011-11-02 14:17:41.000000000 +0400
+++ ./msgpack_unpack.c	2012-05-28 15:06:00.765503368 +0400
@@ -54,7 +54,7 @@
     MSGPACK_UNSERIALIZE_FINISH_ITEM(_unpack, 2);
 
 inline static void msgpack_var_push(
-    php_unserialize_data_t *var_hashx, zval **rval)
+    msgpack_unserialize_data_t *var_hashx, zval **rval)
 {
     var_entries *var_hash, *prev = NULL;
 
@@ -91,7 +91,7 @@
 }
 
 inline static int msgpack_var_access(
-    php_unserialize_data_t *var_hashx, long id, zval ***store)
+    msgpack_unserialize_data_t *var_hashx, long id, zval ***store)
 {
     var_entries *var_hash = var_hashx->first;
 
@@ -118,7 +118,7 @@
 }
 
 inline static void msgpack_stack_push(
-    php_unserialize_data_t *var_hashx, zval **rval, zend_bool save)
+    msgpack_unserialize_data_t *var_hashx, zval **rval, zend_bool save)
 {
     var_entries *var_hash, *prev = NULL;
 
@@ -162,7 +162,7 @@
 }
 
 inline static void msgpack_stack_pop(
-    php_unserialize_data_t *var_hashx, long count)
+    msgpack_unserialize_data_t *var_hashx, long count)
 {
     long i;
     var_entries *var_hash = var_hashx->first_dtor;
@@ -280,14 +280,14 @@
     return ce;
 }
 
-void msgpack_unserialize_var_init(php_unserialize_data_t *var_hashx)
+void msgpack_unserialize_var_init(msgpack_unserialize_data_t *var_hashx)
 {
     var_hashx->first = 0;
     var_hashx->first_dtor = 0;
 }
 
 void msgpack_unserialize_var_destroy(
-    php_unserialize_data_t *var_hashx, zend_bool err)
+    msgpack_unserialize_data_t *var_hashx, zend_bool err)
 {
     void *next;
     long i;
