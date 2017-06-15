--- zlib.c.orig	2016-06-21 19:57:08 UTC
+++ zlib.c
@@ -1480,6 +1480,7 @@ static PHP_MSHUTDOWN_FUNCTION(zlib)
 /* {{{ PHP_RINIT_FUNCTION */
 static PHP_RINIT_FUNCTION(zlib)
 {
+	ZLIBG(output_compression) = 0;
 	ZLIBG(compression_coding) = 0;
     if (!ZLIBG(handler_registered)) {
         ZLIBG(output_compression) = ZLIBG(output_compression_default);
