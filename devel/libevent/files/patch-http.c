--- http.c.orig	Sat Aug 12 11:41:36 2006
+++ http.c	Tue Oct 31 04:12:27 2006
@@ -207,7 +207,7 @@
 	    evhttp_find_header(req->output_headers, "Content-Length") == NULL){
 		char size[12];
 		snprintf(size, sizeof(size), "%ld",
-		    EVBUFFER_LENGTH(req->output_buffer));
+		    (long int)EVBUFFER_LENGTH(req->output_buffer));
 		evhttp_add_header(req->output_headers, "Content-Length", size);
 	}
 }
