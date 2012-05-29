--- ./msgpack_class.c.orig	2011-11-01 05:15:37.000000000 +0400
+++ ./msgpack_class.c	2012-05-28 15:06:00.763502625 +0400
@@ -19,7 +19,7 @@
     zval *retval;
     long offset;
     msgpack_unpack_t mp;
-    php_unserialize_data_t var_hash;
+    msgpack_unserialize_data_t var_hash;
     long php_only;
     zend_bool finished;
     int error;
@@ -188,8 +188,10 @@
 static zend_object_value php_msgpack_base_new(zend_class_entry *ce TSRMLS_DC)
 {
     zend_object_value retval;
-    zval *tmp;
     php_msgpack_base_t *base;
+#if PHP_API_VERSION < 20100412
+    zval *tmp;
+#endif
 
     base = emalloc(sizeof(php_msgpack_base_t));
 
@@ -201,9 +203,13 @@
     base->object.ce = ce;
 #endif
 
+#if PHP_API_VERSION < 20100412
     zend_hash_copy(
         base->object.properties, &ce->default_properties,
         (copy_ctor_func_t)zval_add_ref, (void *)&tmp, sizeof(zval *));
+#else
+    object_properties_init(&base->object, ce);
+#endif
 
     retval.handle = zend_objects_store_put(
         base, (zend_objects_store_dtor_t)zend_objects_destroy_object,
@@ -233,8 +239,10 @@
     zend_class_entry *ce TSRMLS_DC)
 {
     zend_object_value retval;
-    zval *tmp;
     php_msgpack_unpacker_t *unpacker;
+#if PHP_API_VERSION < 20100412
+    zval *tmp;
+#endif
 
     unpacker = emalloc(sizeof(php_msgpack_unpacker_t));
 
@@ -246,9 +254,13 @@
     unpacker->object.ce = ce;
 #endif
 
+#if PHP_API_VERSION < 20100412
     zend_hash_copy(
         unpacker->object.properties, &ce->default_properties,
         (copy_ctor_func_t)zval_add_ref, (void *)&tmp, sizeof(zval *));
+#else
+    object_properties_init(&unpacker->object, ce);
+#endif
 
     retval.handle = zend_objects_store_put(
         unpacker, (zend_objects_store_dtor_t)zend_objects_destroy_object,
@@ -410,7 +422,7 @@
     msgpack_unserialize_var_init(&unpacker->var_hash);
 
     (&unpacker->mp)->user.var_hash =
-        (php_unserialize_data_t *)&unpacker->var_hash;
+        (msgpack_unserialize_data_t *)&unpacker->var_hash;
 }
 
 static ZEND_METHOD(msgpack_unpacker, __destruct)
@@ -533,7 +545,7 @@
         msgpack_unserialize_var_init(&unpacker->var_hash);
 
         (&unpacker->mp)->user.var_hash =
-            (php_unserialize_data_t *)&unpacker->var_hash;
+            (msgpack_unserialize_data_t *)&unpacker->var_hash;
     }
     (&unpacker->mp)->user.retval = (zval *)unpacker->retval;
 
@@ -649,7 +661,7 @@
     msgpack_unserialize_var_init(&unpacker->var_hash);
 
     (&unpacker->mp)->user.var_hash =
-        (php_unserialize_data_t *)&unpacker->var_hash;
+        (msgpack_unserialize_data_t *)&unpacker->var_hash;
 }
 
 void msgpack_init_class()
