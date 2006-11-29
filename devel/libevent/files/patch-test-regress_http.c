--- test/regress_http.c.orig	Sun Oct 15 18:51:59 2006
+++ test/regress_http.c	Wed Nov 29 15:00:35 2006
@@ -125,13 +125,14 @@
 http_readcb(struct bufferevent *bev, void *arg)
 {
 	const char *what = "This is funny";
+	int done;
 
  	event_debug(("%s: %s\n", __func__, EVBUFFER_DATA(bev->input)));
 	
 	if (evbuffer_find(bev->input, what, strlen(what)) != NULL) {
 		struct evhttp_request *req = evhttp_request_new(NULL, NULL);
 		req->kind = EVHTTP_RESPONSE;
-		int done = evhttp_parse_lines(req, bev->input);
+		done = evhttp_parse_lines(req, bev->input);
 
 		if (done == 1 &&
 		    evhttp_find_header(req->input_headers,
@@ -163,9 +164,11 @@
 void
 http_basic_cb(struct evhttp_request *req, void *arg)
 {
+	struct evbuffer *evb;
+
 	event_debug((stderr, "%s: called\n", __func__));
 
-	struct evbuffer *evb = evbuffer_new();
+	evb = evbuffer_new();
 	evbuffer_add_printf(evb, "This is funny");
 
 	evhttp_send_reply(req, HTTP_OK, "Everything is fine", evb);
@@ -355,6 +358,8 @@
 void
 http_post_cb(struct evhttp_request *req, void *arg)
 {
+	struct evbuffer *evb;
+
 	event_debug((stderr, "%s: called\n", __func__));
 
 	/* Yes, we are expecting a post request */
@@ -365,7 +370,7 @@
 
 	if (EVBUFFER_LENGTH(req->input_buffer) != strlen(POST_DATA)) {
 		fprintf(stdout, "FAILED (length: %ld vs %ld)\n",
-		    EVBUFFER_LENGTH(req->input_buffer), strlen(POST_DATA));
+		    (long int)EVBUFFER_LENGTH(req->input_buffer), (long int)strlen(POST_DATA));
 		exit(1);
 	}
 
@@ -377,7 +382,7 @@
 		exit(1);
 	}
 	
-	struct evbuffer *evb = evbuffer_new();
+	evb = evbuffer_new();
 	evbuffer_add_printf(evb, "This is funny");
 
 	evhttp_send_reply(req, HTTP_OK, "Everything is fine", evb);
@@ -403,7 +408,7 @@
 
 	if (EVBUFFER_LENGTH(req->input_buffer) != strlen(what)) {
 		fprintf(stderr, "FAILED (length %ld vs %ld)\n",
-		    EVBUFFER_LENGTH(req->input_buffer), strlen(what));
+		    (long int)EVBUFFER_LENGTH(req->input_buffer), (long int)strlen(what));
 		exit(1);
 	}
 	
