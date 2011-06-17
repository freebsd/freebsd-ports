--- main/rfc1867.c.orig	2011/06/12 15:03:18
+++ main/rfc1867.c	2011/06/12 15:14:18
@@ -1223,7 +1223,7 @@
 #endif
 
 			if (!is_anonymous) {
-				if (s && s > filename) {
+				if (s && s >= filename) {
 					safe_php_register_variable(lbuf, s+1, strlen(s+1), NULL, 0 TSRMLS_CC);
 				} else {
 					safe_php_register_variable(lbuf, filename, strlen(filename), NULL, 0 TSRMLS_CC);
@@ -1236,7 +1236,7 @@
 			} else {
 				snprintf(lbuf, llen, "%s[name]", param);
 			}
-			if (s && s > filename) {
+			if (s && s >= filename) {
 				register_http_post_files_variable(lbuf, s+1, http_post_files, 0 TSRMLS_CC);
 			} else {
 				register_http_post_files_variable(lbuf, filename, http_post_files, 0 TSRMLS_CC);
