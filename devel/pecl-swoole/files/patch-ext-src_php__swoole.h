--- ext-src/php_swoole.h.orig	2020-11-27 11:02:33.000000000 +0800
+++ ext-src/php_swoole.h	2020-11-30 16:16:31.186209000 +0800
@@ -912,7 +912,7 @@ static sw_inline zend_bool sw_zend_is_callable_at_fram
 {
     zend_string *name;
     zend_bool ret;
-#if PHP_VERSION_ID < 80000
+#if PHP_VERSION_ID < 80001
     ret = zend_is_callable_ex(zcallable, zobject ? Z_OBJ_P(zobject) : NULL, check_flags, &name, fci_cache, error);
 #else
     ret = zend_is_callable_at_frame(zcallable, zobject ? Z_OBJ_P(zobject) : NULL, frame, check_flags, fci_cache, error);
