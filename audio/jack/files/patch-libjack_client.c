--- libjack/client.c.orig	2016-09-14 17:41:53 UTC
+++ libjack/client.c
@@ -69,6 +69,30 @@
 static pthread_mutex_t client_lock;
 static pthread_cond_t client_ready;
 
+/*
+ * The following read/write wrappers handle the case of interruption
+ * by system signals:
+ */
+static int
+read_retry(int fd, void *dst, int size)
+{
+	int error;
+	do {
+		error = read(fd, dst, size);
+	} while (error == -1 && errno == EINTR);
+	return (error);
+}
+
+static int
+write_retry(int fd, const void *src, int size)
+{
+	int error;
+	do {
+		error = write(fd, src, size);
+	} while (error == -1 && errno == EINTR);
+	return (error);
+}
+
 static int
 jack_client_close_aux(jack_client_t *client);
 
@@ -252,7 +276,7 @@ oop_client_deliver_request (void *ptr, j
 	int wok, rok;
 	jack_client_t *client = (jack_client_t*)ptr;
 
-	wok = (write (client->request_fd, req, sizeof(*req))
+	wok = (write_retry (client->request_fd, req, sizeof(*req))
 	       == sizeof(*req));
 
 	/* if necessary, add variable length key data after a PropertyChange request
@@ -260,7 +284,7 @@ oop_client_deliver_request (void *ptr, j
 
 	if (req->type == PropertyChangeNotify) {
 		if (req->x.property.keylen) {
-			if (write (client->request_fd, req->x.property.key, req->x.property.keylen) != req->x.property.keylen) {
+			if (write_retry (client->request_fd, req->x.property.key, req->x.property.keylen) != req->x.property.keylen) {
 				jack_error ("cannot send property key of length %d to server",
 					    req->x.property.keylen);
 				req->status = -1;
@@ -269,7 +293,7 @@ oop_client_deliver_request (void *ptr, j
 		}
 	}
 
-	rok = (read (client->request_fd, req, sizeof(*req))
+	rok = (read_retry (client->request_fd, req, sizeof(*req))
 	       == sizeof(*req));
 
 	if (wok && rok) {               /* everything OK? */
@@ -838,14 +862,14 @@ server_event_connect (jack_client_t *cli
 
 	jack_uuid_copy (&req.client_id, client->control->uuid);
 
-	if (write (fd, &req, sizeof(req)) != sizeof(req)) {
-		jack_error ("cannot write event connect request to server (%s)",
+	if (write_retry (fd, &req, sizeof(req)) != sizeof(req)) {
+		jack_error ("cannot write_retry event connect request to server (%s)",
 			    strerror (errno));
 		close (fd);
 		return -1;
 	}
 
-	if (read (fd, &res, sizeof(res)) != sizeof(res)) {
+	if (read_retry (fd, &res, sizeof(res)) != sizeof(res)) {
 		jack_error ("cannot read event connect result from server (%s)",
 			    strerror (errno));
 		close (fd);
@@ -1110,14 +1134,14 @@ jack_request_client (ClientType type,
 	snprintf (req.object_data, sizeof(req.object_data),
 		  "%s", va->load_init);
 
-	if (write (*req_fd, &req, sizeof(req)) != sizeof(req)) {
+	if (write_retry (*req_fd, &req, sizeof(req)) != sizeof(req)) {
 		jack_error ("cannot send request to jack server (%s)",
 			    strerror (errno));
 		*status |= (JackFailure | JackServerError);
 		goto fail;
 	}
 
-	if (read (*req_fd, res, sizeof(*res)) != sizeof(*res)) {
+	if (read_retry (*req_fd, res, sizeof(*res)) != sizeof(*res)) {
 
 		if (errno == 0) {
 			/* server shut the socket */
@@ -1513,7 +1537,7 @@ jack_internal_client_close (const char *
 		return;
 	}
 
-	if (write (fd, &req, sizeof(req)) != sizeof(req)) {
+	if (write_retry (fd, &req, sizeof(req)) != sizeof(req)) {
 		jack_error ("cannot deliver ClientUnload request to JACK "
 			    "server.");
 	}
@@ -1649,7 +1673,7 @@ jack_session_notify (jack_client_t* clie
 
 	request.x.session.type = code;
 
-	if ( (write (client->request_fd, &request, sizeof(request))
+	if ( (write_retry (client->request_fd, &request, sizeof(request))
 	      != sizeof(request)) ) {
 		jack_error ("cannot send request type %d to server",
 			    request.type);
@@ -1659,7 +1683,7 @@ jack_session_notify (jack_client_t* clie
 	while ( 1 ) {
 		jack_uuid_t uid;
 
-		if (read (client->request_fd, &uid, sizeof(uid)) != sizeof(uid)) {
+		if (read_retry (client->request_fd, &uid, sizeof(uid)) != sizeof(uid)) {
 			jack_error ("cannot read result for request type %d from"
 				    " server (%s)", request.type, strerror (errno));
 			goto out;
@@ -1681,19 +1705,19 @@ jack_session_notify (jack_client_t* clie
 			break;
 		}
 
-		if (read (client->request_fd, (char*)retval[num_replies - 1].client_name, JACK_CLIENT_NAME_SIZE)
+		if (read_retry (client->request_fd, (char*)retval[num_replies - 1].client_name, JACK_CLIENT_NAME_SIZE)
 		    != JACK_CLIENT_NAME_SIZE) {
 			jack_error ("cannot read result for request type %d from"
 				    " server (%s)", request.type, strerror (errno));
 			goto out;
 		}
-		if (read (client->request_fd, (char*)retval[num_replies - 1].command, JACK_PORT_NAME_SIZE)
+		if (read_retry (client->request_fd, (char*)retval[num_replies - 1].command, JACK_PORT_NAME_SIZE)
 		    != JACK_PORT_NAME_SIZE) {
 			jack_error ("cannot read result for request type %d from"
 				    " server (%s)", request.type, strerror (errno));
 			goto out;
 		}
-		if (read (client->request_fd, &retval[num_replies - 1].flags, sizeof(retval[num_replies - 1].flags) )
+		if (read_retry (client->request_fd, &retval[num_replies - 1].flags, sizeof(retval[num_replies - 1].flags) )
 		    != sizeof(retval[num_replies - 1].flags) ) {
 			jack_error ("cannot read result for request type %d from"
 				    " server (%s)", request.type, strerror (errno));
@@ -1812,7 +1836,7 @@ jack_client_process_events (jack_client_
 		/* server has sent us an event. process the
 		 * event and reply */
 
-		if (read (client->event_fd, &event, sizeof(event))
+		if (read_retry (client->event_fd, &event, sizeof(event))
 		    != sizeof(event)) {
 			jack_error ("cannot read server event (%s)",
 				    strerror (errno));
@@ -1822,7 +1846,7 @@ jack_client_process_events (jack_client_
 		if (event.type == PropertyChange) {
 			if (event.y.key_size) {
 				key = (char*)malloc (event.y.key_size);
-				if (read (client->event_fd, key, event.y.key_size) !=
+				if (read_retry (client->event_fd, key, event.y.key_size) !=
 				    event.y.key_size) {
 					jack_error ("cannot read property change key (%s)",
 						    strerror (errno));
@@ -1941,7 +1965,7 @@ jack_client_process_events (jack_client_
 		DEBUG ("client has dealt with the event, writing "
 		       "response on event fd");
 
-		if (write (client->event_fd, &status, sizeof(status))
+		if (write_retry (client->event_fd, &status, sizeof(status))
 		    != sizeof(status)) {
 			jack_error ("cannot send event response to "
 				    "engine (%s)", strerror (errno));
@@ -1961,7 +1985,7 @@ jack_wake_next_client (jack_client_t* cl
 	int pret = 0;
 	char c = 0;
 
-	if (write (client->graph_next_fd, &c, sizeof(c))
+	if (write_retry (client->graph_next_fd, &c, sizeof(c))
 	    != sizeof(c)) {
 		DEBUG ("cannot write byte to fd %d", client->graph_next_fd);
 		jack_error ("cannot continue execution of the "
@@ -1989,7 +2013,7 @@ jack_wake_next_client (jack_client_t* cl
 	}
 
 	if (pret > 0 && (pfds[0].revents & POLLIN)) {
-		if (read (client->graph_wait_fd, &c, sizeof(c))
+		if (read_retry (client->graph_wait_fd, &c, sizeof(c))
 		    != sizeof(c)) {
 			jack_error ("cannot complete execution of the "
 				    "processing graph (%s)", strerror (errno));
