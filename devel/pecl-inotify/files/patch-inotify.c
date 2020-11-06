--- inotify.c.orig	2016-01-30 12:34:05 UTC
+++ inotify.c
@@ -28,6 +28,11 @@
 #include "ext/standard/info.h"
 #include "php_inotify.h"
 
+#if PHP_MAJOR_VERSION >= 8
+#define TSRMLS_CC
+#define TSRMLS_DC
+#endif
+
 /* {{{ arginfo */
 ZEND_BEGIN_ARG_INFO_EX(arginfo_inotify_init, 0, ZEND_RETURN_VALUE, 0)
 ZEND_END_ARG_INFO()
