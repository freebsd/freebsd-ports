--- paradox.c.orig	Tue Feb 14 12:36:43 2006
+++ paradox.c	Tue Feb 14 12:37:11 2006
@@ -425,6 +425,7 @@
 	FILE *fp = NULL;
 	pxdoc_t *pxdoc = NULL;
 	zval *object = getThis();
+	php_stream *stream;
 
 	if (object) {
 		if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &zfp)) {
@@ -438,8 +439,6 @@
 		PXDOC_FROM_ZVAL(pxdoc, &zpx);
 	}
 
-	php_stream *stream;
-
 	php_stream_from_zval(stream, &zfp);
 	
 	if (php_stream_cast(stream, PHP_STREAM_AS_STDIO, (void*)&fp, 1) == FAILURE)	{
@@ -468,6 +467,7 @@
 	pxfield_t *pxf;
 	int numfields, i;
 	zval *object = getThis();
+	php_stream *stream;
 
 	if (object) {
 		if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rz", &zfp, &schema)) {
@@ -486,7 +486,6 @@
 		RETURN_FALSE;
 	}
 
-	php_stream *stream;
 	php_stream_from_zval(stream, &zfp);
 	
 	if (php_stream_cast(stream, PHP_STREAM_AS_STDIO, (void*)&fp, 1) == FAILURE)	{
