--- xdebug_compat.h.orig	2018-12-23 17:22:30 UTC
+++ xdebug_compat.h
@@ -75,8 +75,4 @@ zend_bool xdebug_zend_hash_apply_protection_end(HashTa
 #  define XDEBUG_ZEND_CONSTANT_MODULE_NUMBER(v) ((v)->module_number)
 # endif
 
-# if PHP_VERSION_ID < 70300
-typedef void (*zif_handler)(INTERNAL_FUNCTION_PARAMETERS);
-# endif
-
 #endif
