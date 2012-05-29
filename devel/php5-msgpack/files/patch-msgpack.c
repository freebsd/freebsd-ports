--- ./msgpack.c.orig	2011-10-31 10:15:40.000000000 +0400
+++ ./msgpack.c	2012-05-28 15:06:00.763502625 +0400
@@ -141,11 +141,15 @@
 PS_SERIALIZER_ENCODE_FUNC(msgpack)
 {
     smart_str buf = {0};
-    php_serialize_data_t var_hash;
+    msgpack_serialize_data_t var_hash;
 
     PHP_VAR_SERIALIZE_INIT(var_hash);
 
+#if PHP_API_VERSION < 20100412
     msgpack_serialize_zval(&buf, PS(http_session_vars), &var_hash TSRMLS_CC);
+#else
+    msgpack_serialize_zval(&buf, PS(http_session_vars), var_hash TSRMLS_CC);
+#endif
 
     if (newlen)
     {
@@ -172,7 +176,7 @@
     zval **value;
     size_t off = 0;
     msgpack_unpack_t mp;
-    php_unserialize_data_t var_hash;
+    msgpack_unserialize_data_t var_hash;
 
     ALLOC_INIT_ZVAL(tmp);
 
@@ -181,7 +185,7 @@
     msgpack_unserialize_var_init(&var_hash);
 
     mp.user.retval = (zval *)tmp;
-    mp.user.var_hash = (php_unserialize_data_t *)&var_hash;
+    mp.user.var_hash = (msgpack_unserialize_data_t *)&var_hash;
 
     ret = template_execute(&mp, (char *)val, (size_t)vallen, &off);
 
@@ -224,11 +228,15 @@
 
 PHP_MSGPACK_API void php_msgpack_serialize(smart_str *buf, zval *val TSRMLS_DC)
 {
-    php_serialize_data_t var_hash;
+    msgpack_serialize_data_t var_hash;
 
     PHP_VAR_SERIALIZE_INIT(var_hash);
 
+#if PHP_API_VERSION < 20100412
     msgpack_serialize_zval(buf, val, &var_hash TSRMLS_CC);
+#else
+    msgpack_serialize_zval(buf, val, var_hash TSRMLS_CC);
+#endif
 
     PHP_VAR_SERIALIZE_DESTROY(var_hash);
 }
@@ -239,7 +247,7 @@
     int ret;
     size_t off = 0;
     msgpack_unpack_t mp;
-    php_unserialize_data_t var_hash;
+    msgpack_unserialize_data_t var_hash;
 
     if (str_len <= 0)
     {
@@ -251,7 +259,7 @@
     msgpack_unserialize_var_init(&var_hash);
 
     mp.user.retval = (zval *)return_value;
-    mp.user.var_hash = (php_unserialize_data_t *)&var_hash;
+    mp.user.var_hash = (msgpack_unserialize_data_t *)&var_hash;
 
     ret = template_execute(&mp, str, (size_t)str_len, &off);
 
