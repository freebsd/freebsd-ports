--- php_zookeeper_session.c.orig	2019-12-11 01:31:04 UTC
+++ php_zookeeper_session.c
@@ -25,6 +25,12 @@
 #include "php_zookeeper_private.h"
 #include "php_zookeeper_session.h"
 
+#if PHP_MAJOR_VERSION >= 8
+#define TSRMLS_D void
+#define TSRMLS_DC
+#define TSRMLS_CC
+#endif
+
 #ifdef HAVE_ZOOKEEPER_SESSION
 
 #define ZK_SESS_DATA php_zookeeper_session *session = PS_GET_MOD_DATA();
