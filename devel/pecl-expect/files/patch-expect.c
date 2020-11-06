--- expect.c.orig	2020-01-13 18:27:49 UTC
+++ expect.c
@@ -22,6 +22,10 @@
 #include <string.h>
 #include <errno.h>
 
+#if PHP_MAJOR_VERSION >= 8
+#define TSRMLS_CC
+#endif
+
 ZEND_BEGIN_ARG_INFO_EX(arginfo_expect_popen, 0, 0, 1)
 	ZEND_ARG_INFO(0, command)
 ZEND_END_ARG_INFO()
@@ -314,7 +318,7 @@ PHP_FUNCTION(expect_expectl)
 #endif
 	php_stream *stream;
 	int fd, argc;
-	ulong key;
+	zend_ulong key;
 	
 	if (ZEND_NUM_ARGS() < 2 || ZEND_NUM_ARGS() > 3) { WRONG_PARAM_COUNT; }
 
