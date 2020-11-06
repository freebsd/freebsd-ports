--- src/tarantool_network.c.orig	2020-06-29 22:41:13 UTC
+++ src/tarantool_network.c
@@ -11,6 +11,11 @@
 #include "php_tarantool.h"
 #include "tarantool_network.h"
 
+#if PHP_MAJOR_VERSION >= 8
+#define TSRMLS_CC
+#define TSRMLS_FETCH()
+#endif
+
 void double_to_tv(double tm, struct timeval *tv) {
 	tv->tv_sec = floor(tm);
 	tv->tv_usec = floor((tm - floor(tm)) * pow(10, 6));
