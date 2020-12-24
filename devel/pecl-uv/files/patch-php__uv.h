--- php_uv.h.orig	2019-05-01 11:04:19 UTC
+++ php_uv.h
@@ -40,7 +40,11 @@
 #elif !defined(PHP_WIN32)
 typedef struct {
 	int bsd_socket;
-	/* other fields are not interesting... */
+	int type;
+	int error;
+	int blocking;
+	zval zstream;
+	zend_object std;
 } php_socket;
 #endif
 
