--- lib/ssl/src/ssl_connection.hrl.orig	2015-03-31 12:32:52.000000000 +0000
+++ lib/ssl/src/ssl_connection.hrl	2017-12-14 13:18:02.736638000 +0000
@@ -53,7 +53,8 @@
           session               :: #session{} | secret_printout(),
 	  session_cache         :: db_handle(),
 	  session_cache_cb      :: atom(),
-          negotiated_version    :: ssl_record:ssl_version(),
+          negotiated_version    :: ssl_record:ssl_version() | 'undefined',
+          client_hello_version  :: ssl_record:ssl_version() | 'undefined',
           client_certificate_requested = false :: boolean(),
 	  key_algorithm         :: ssl_cipher:key_algo(),
 	  hashsign_algorithm = {undefined, undefined},
