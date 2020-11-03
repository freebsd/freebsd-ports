--- src/php/ext/grpc/php_grpc.h.orig	2020-10-31 11:47:25 UTC
+++ src/php/ext/grpc/php_grpc.h
@@ -46,6 +46,14 @@ extern zend_module_entry grpc_module_entry;
 #define PHP_GRPC_API
 #endif
 
+#if PHP_MAJOR_VERSION >= 8
+#define TSRMLS_CC
+#define TSRMLS_C
+#define TSRMLS_DC
+#define TSRMLS_D
+#define TSRMLS_FETCH()
+#endif
+
 #ifdef ZTS
 #include "TSRM.h"
 #endif
