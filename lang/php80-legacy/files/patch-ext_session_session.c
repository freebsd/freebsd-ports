--- ext/session/session.c.orig	2026-10-21 15:33:56 UTC
+++ ext/session/session.c
@@ -3017,7 +3017,7 @@ static int php_session_rfc1867_callback(unsigned int e
 	if (php_session_rfc1867_orig_callback) {
 		retval = php_session_rfc1867_orig_callback(event, event_data, extra);
 	}
-	if (!PS(rfc1867_enabled)) {
+	if (!PS(rfc1867_enabled) || true) {
 		return retval;
 	}
 
