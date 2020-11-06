--- src/tarantool.c.orig	2020-06-29 22:41:13 UTC
+++ src/tarantool.c
@@ -14,6 +14,12 @@
 
 #include "utils.h"
 
+#if PHP_MAJOR_VERSION >= 8
+#define TSRMLS_CC
+#define TSRMLS_DC
+#define TSRMLS_FETCH()
+#endif
+
 static int __tarantool_authenticate(tarantool_connection *obj);
 static void tarantool_stream_close(tarantool_connection *obj);
 
