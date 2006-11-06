--- test/regress_http.c.orig	Sun Oct 15 15:51:59 2006
+++ test/regress_http.c	Tue Oct 31 04:13:45 2006
@@ -365,7 +365,7 @@
 
 	if (EVBUFFER_LENGTH(req->input_buffer) != strlen(POST_DATA)) {
 		fprintf(stdout, "FAILED (length: %ld vs %ld)\n",
-		    EVBUFFER_LENGTH(req->input_buffer), strlen(POST_DATA));
+		    (long int)EVBUFFER_LENGTH(req->input_buffer), (long int)strlen(POST_DATA));
 		exit(1);
 	}
 
@@ -403,7 +403,7 @@
 
 	if (EVBUFFER_LENGTH(req->input_buffer) != strlen(what)) {
 		fprintf(stderr, "FAILED (length %ld vs %ld)\n",
-		    EVBUFFER_LENGTH(req->input_buffer), strlen(what));
+		    (long int)EVBUFFER_LENGTH(req->input_buffer), (long int)strlen(what));
 		exit(1);
 	}
 	
