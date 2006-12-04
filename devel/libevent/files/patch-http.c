#
# Fix build with old gcc
#
--- http.c.orig	Sat Dec  2 19:30:04 2006
+++ http.c	Mon Dec  4 11:17:38 2006
@@ -518,6 +518,7 @@
 evhttp_connection_done(struct evhttp_connection *evcon)
 {
 	struct evhttp_request *req = TAILQ_FIRST(&evcon->requests);
+	int need_close;
 
 	/*
 	 * if this is an incoming connection, we need to leave the request
@@ -527,7 +528,7 @@
 		TAILQ_REMOVE(&evcon->requests, req, next);
 		req->evcon = NULL;
 
-		int need_close = 
+		need_close = 
 		    evhttp_is_connection_close(req->input_headers) ||
 		    evhttp_is_connection_close(req->output_headers);
 
