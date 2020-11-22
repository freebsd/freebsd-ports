--- ext-src/php_swoole.h.orig	2020-11-22 13:36:39 UTC
+++ ext-src/php_swoole.h
@@ -912,10 +912,11 @@ static sw_inline zend_bool sw_zend_is_callable_at_fram
 {
     zend_string *name;
     zend_bool ret;
-#if PHP_VERSION_ID < 80000
+#if PHP_VERSION_ID < 80001
     ret = zend_is_callable_ex(zcallable, zobject ? Z_OBJ_P(zobject) : NULL, check_flags, &name, fci_cache, error);
 #else
-    ret = zend_is_callable_at_frame(zcallable, zobject ? Z_OBJ_P(zobject) : NULL, frame, check_flags, &name, fci_cache, error);
+    ret = zend_is_callable_at_frame(zcallable, zobject ? Z_OBJ_P(zobject) : NULL, frame, check_flags, fci_cache, error);
+    name = zend_get_callable_name_ex(zcallable, zobject);
 #endif
     if (callable_name)
     {
