--- apc_serializer.h.orig	2011-03-14 20:32:48.000000000 +0800
+++ apc_serializer.h	2014-07-03 23:40:39.234972645 +0800
@@ -54,7 +54,7 @@
     
     ALLOC_INIT_ZVAL(apc_magic_constant);
 
-    if (zend_get_constant(APC_SERIALIZER_CONSTANT, sizeof(APC_SERIALIZER_CONSTANT)-1, apc_magic_constant)) { 
+    if (zend_get_constant(APC_SERIALIZER_CONSTANT, sizeof(APC_SERIALIZER_CONSTANT)-1, apc_magic_constant TSRMLS_CC)) { 
         if(apc_magic_constant) {
             apc_register_serializer_t register_func = (apc_register_serializer_t)(Z_LVAL_P(apc_magic_constant));
             if(register_func) {
