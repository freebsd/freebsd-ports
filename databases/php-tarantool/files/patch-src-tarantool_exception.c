--- src/tarantool_exception.c.orig	2020-06-29 22:41:13 UTC
+++ src/tarantool_exception.c
@@ -4,6 +4,10 @@
 
 #include "tarantool_exception.h"
 
+#if PHP_MAJOR_VERSION >= 8
+#define TSRMLS_DC
+#endif
+
 zend_class_entry *TarantoolException_ptr;
 zend_class_entry *TarantoolIOException_ptr;
 zend_class_entry *TarantoolClientError_ptr;
