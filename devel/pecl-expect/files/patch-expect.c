--- expect.c.orig	2020-01-13 18:27:49 UTC
+++ expect.c
@@ -314,7 +314,7 @@ PHP_FUNCTION(expect_expectl)
 #endif
 	php_stream *stream;
 	int fd, argc;
-	ulong key;
+	zend_ulong key;
 	
 	if (ZEND_NUM_ARGS() < 2 || ZEND_NUM_ARGS() > 3) { WRONG_PARAM_COUNT; }
 
