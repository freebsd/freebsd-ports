--- ext/zlib/zlib.c.orig	2026-10-22 02:28:48 UTC
+++ ext/zlib/zlib.c
@@ -1420,6 +1420,7 @@ static PHP_RINIT_FUNCTION(zlib)
 /* {{{ PHP_RINIT_FUNCTION */
 static PHP_RINIT_FUNCTION(zlib)
 {
+	ZLIBG(output_compression) = 0;
 	ZLIBG(compression_coding) = 0;
     if (!ZLIBG(handler_registered)) {
         ZLIBG(output_compression) = ZLIBG(output_compression_default);
