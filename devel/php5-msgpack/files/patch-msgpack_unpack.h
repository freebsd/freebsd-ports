--- ./msgpack_unpack.h.orig	2011-07-27 09:50:36.000000000 +0400
+++ ./msgpack_unpack.h	2012-05-28 15:06:00.765503368 +0400
@@ -16,17 +16,19 @@
     MSGPACK_UNPACK_PARSE_ERROR = -1,
 } msgpack_unpack_return;
 
+typedef struct php_unserialize_data msgpack_unserialize_data_t;
+
 typedef struct {
     zval *retval;
     long deps;
-    php_unserialize_data_t *var_hash;
+    msgpack_unserialize_data_t *var_hash;
     long stack[MSGPACK_EMBED_STACK_SIZE];
     int type;
 } msgpack_unserialize_data;
 
-void msgpack_unserialize_var_init(php_unserialize_data_t *var_hashx);
+void msgpack_unserialize_var_init(msgpack_unserialize_data_t *var_hashx);
 void msgpack_unserialize_var_destroy(
-    php_unserialize_data_t *var_hashx, zend_bool err);
+    msgpack_unserialize_data_t *var_hashx, zend_bool err);
 
 void msgpack_unserialize_init(msgpack_unserialize_data *unpack);
 
