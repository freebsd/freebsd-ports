--- zlib.c.orig	2012-07-09 15:25:31.000000000 +0200
+++ zlib.c	2012-07-09 15:26:07.000000000 +0200
@@ -957,6 +957,7 @@
 /* {{{ PHP_RINIT_FUNCTION */
 static PHP_RINIT_FUNCTION(zlib)
 {
+	ZLIBG(output_compression) = 0;
 	ZLIBG(compression_coding) = 0;
 
 	php_zlib_output_compression_start(TSRMLS_C);
