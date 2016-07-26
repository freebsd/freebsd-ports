--- zlib.c.orig	2016-06-21 11:11:59 UTC
+++ zlib.c
@@ -977,6 +977,7 @@ static PHP_MSHUTDOWN_FUNCTION(zlib)
 /* {{{ PHP_RINIT_FUNCTION */
 static PHP_RINIT_FUNCTION(zlib)
 {
+	ZLIBG(output_compression) = 0;
 	ZLIBG(compression_coding) = 0;
     if (!ZLIBG(handler_registered)) {
         ZLIBG(output_compression) = ZLIBG(output_compression_default);
