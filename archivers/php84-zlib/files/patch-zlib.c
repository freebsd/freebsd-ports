--- zlib.c.orig	2023-06-06 15:54:29 UTC
+++ zlib.c
@@ -1380,6 +1380,7 @@ static PHP_MSHUTDOWN_FUNCTION(zlib)
 /* {{{ PHP_RINIT_FUNCTION */
 static PHP_RINIT_FUNCTION(zlib)
 {
+	ZLIBG(output_compression) = 0;
 	ZLIBG(compression_coding) = 0;
 	if (!ZLIBG(handler_registered)) {
 		ZLIBG(output_compression) = ZLIBG(output_compression_default);
