--- test/regress_http.c.orig	Wed Nov 29 00:22:10 2006
+++ test/regress_http.c	Mon Dec  4 11:04:42 2006
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
 	event_debug(("%s: called\n", __func__));
 
-	struct evbuffer *evb = evbuffer_new();
+	evb = evbuffer_new();
 	evbuffer_add_printf(evb, "This is funny");
 
 	evhttp_send_reply(req, HTTP_OK, "Everything is fine", evb);
@@ -380,6 +383,8 @@
 void
 http_post_cb(struct evhttp_request *req, void *arg)
 {
+	struct evbuffer *evb;
+
 	event_debug(("%s: called\n", __func__));
 
 	/* Yes, we are expecting a post request */
@@ -390,7 +395,7 @@
 
 	if (EVBUFFER_LENGTH(req->input_buffer) != strlen(POST_DATA)) {
 		fprintf(stdout, "FAILED (length: %ld vs %ld)\n",
-		    EVBUFFER_LENGTH(req->input_buffer), strlen(POST_DATA));
+		    (long int)EVBUFFER_LENGTH(req->input_buffer), (long int)strlen(POST_DATA));
 		exit(1);
 	}
 
@@ -402,7 +407,7 @@
 		exit(1);
 	}
 	
-	struct evbuffer *evb = evbuffer_new();
+	evb = evbuffer_new();
 	evbuffer_add_printf(evb, "This is funny");
 
 	evhttp_send_reply(req, HTTP_OK, "Everything is fine", evb);
@@ -428,7 +433,7 @@
 
 	if (EVBUFFER_LENGTH(req->input_buffer) != strlen(what)) {
 		fprintf(stderr, "FAILED (length %ld vs %ld)\n",
-		    EVBUFFER_LENGTH(req->input_buffer), strlen(what));
+		    (long int)EVBUFFER_LENGTH(req->input_buffer), (long int)strlen(what));
 		exit(1);
 	}
 	
