--- sapi/apache2handler/sapi_apache2.c.orig	Thu Nov  3 10:13:33 2005
+++ sapi/apache2handler/sapi_apache2.c	Thu Nov  3 10:14:41 2005
@@ -535,7 +535,7 @@
 		if (!parent_req) {
 			parent_req = ctx->r;
 		}
-		if (parent_req && strcmp(parent_req->handler, PHP_MAGIC_TYPE) && strcmp(parent_req->handler, PHP_SOURCE_MAGIC_TYPE) && strcmp(parent_req->handler, PHP_SCRIPT)) {
+		if (parent_req && parent_req->handler && strcmp(parent_req->handler, PHP_MAGIC_TYPE) && strcmp(parent_req->handler, PHP_SOURCE_MAGIC_TYPE) && strcmp(parent_req->handler, PHP_SCRIPT)) {
 			if (php_apache_request_ctor(r, ctx TSRMLS_CC)!=SUCCESS) {
 				zend_bailout();
 			}
