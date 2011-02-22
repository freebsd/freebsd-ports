--- http.c.orig	2011-02-22 09:41:25.224559892 +0100
+++ http.c	2011-02-22 09:42:00.208495705 +0100
@@ -390,7 +398,7 @@
 	/* Add the content length on a post request if missing */
 	if (req->type == EVHTTP_REQ_POST &&
 	    evhttp_find_header(req->output_headers, "Content-Length") == NULL){
-		char size[12];
+		char size[22];
 		evutil_snprintf(size, sizeof(size), "%ld",
 		    (long)EVBUFFER_LENGTH(req->output_buffer));
 		evhttp_add_header(req->output_headers, "Content-Length", size);
@@ -447,7 +455,7 @@
 {
 	if (evhttp_find_header(headers, "Transfer-Encoding") == NULL &&
 	    evhttp_find_header(headers,	"Content-Length") == NULL) {
-		char len[12];
+		char len[22];
 		evutil_snprintf(len, sizeof(len), "%ld", content_length);
 		evhttp_add_header(headers, "Content-Length", len);
 	}
