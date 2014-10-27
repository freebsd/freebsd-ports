--- libjack/client.c.orig	2014-10-23 09:09:09.000000000 +0200
+++ libjack/client.c	2014-10-23 09:20:15.000000000 +0200
@@ -116,6 +116,30 @@
 
 char *jack_tmpdir = DEFAULT_TMP_DIR;
 
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
 jack_get_tmpdir ()
 {
@@ -248,7 +272,7 @@
 	int wok, rok;
 	jack_client_t *client = (jack_client_t*) ptr;
 
-	wok = (write (client->request_fd, req, sizeof (*req))
+	wok = (write_retry (client->request_fd, req, sizeof (*req))
 	       == sizeof (*req));
 
         /* if necessary, add variable length key data after a PropertyChange request
@@ -256,7 +280,7 @@
         
         if (req->type == PropertyChangeNotify) {
                 if (req->x.property.keylen) {
-                        if (write (client->request_fd, req->x.property.key, req->x.property.keylen) != req->x.property.keylen) {
+                        if (write_retry (client->request_fd, req->x.property.key, req->x.property.keylen) != req->x.property.keylen) {
                                 jack_error ("cannot send property key of length %d to server",
                                             req->x.property.keylen);
                                 req->status = -1;
@@ -265,7 +289,7 @@
                 }
         }
 
-	rok = (read (client->request_fd, req, sizeof (*req))
+	rok = (read_retry (client->request_fd, req, sizeof (*req))
 	       == sizeof (*req));
 
 	if (wok && rok) {		/* everything OK? */
@@ -822,14 +846,14 @@
 
 	jack_uuid_copy (&req.client_id, client->control->uuid);
 
-	if (write (fd, &req, sizeof (req)) != sizeof (req)) {
+	if (write_retry (fd, &req, sizeof (req)) != sizeof (req)) {
 		jack_error ("cannot write event connect request to server (%s)",
 			    strerror (errno));
 		close (fd);
 		return -1;
 	}
 
-	if (read (fd, &res, sizeof (res)) != sizeof (res)) {
+	if (read_retry (fd, &res, sizeof (res)) != sizeof (res)) {
 		jack_error ("cannot read event connect result from server (%s)",
 			    strerror (errno));
 		close (fd);
@@ -1070,14 +1094,14 @@
 	snprintf (req.object_data, sizeof (req.object_data),
 		  "%s", va->load_init);
 
-	if (write (*req_fd, &req, sizeof (req)) != sizeof (req)) {
+	if (write_retry (*req_fd, &req, sizeof (req)) != sizeof (req)) {
 		jack_error ("cannot send request to jack server (%s)",
 			    strerror (errno));
 		*status |= (JackFailure|JackServerError);
 		goto fail;
 	}
 
-	if (read (*req_fd, res, sizeof (*res)) != sizeof (*res)) {
+	if (read_retry (*req_fd, res, sizeof (*res)) != sizeof (*res)) {
 
 		if (errno == 0) {
 			/* server shut the socket */
@@ -1456,7 +1480,7 @@
 		return;
 	}
 
-	if (write (fd, &req, sizeof (req)) != sizeof(req)) {
+	if (write_retry (fd, &req, sizeof (req)) != sizeof(req)) {
 		jack_error ("cannot deliver ClientUnload request to JACK "
 			    "server.");
 	}
@@ -1582,7 +1606,7 @@
 
 	request.x.session.type = code;
 	
-	if( (write (client->request_fd, &request, sizeof (request))
+	if( (write_retry (client->request_fd, &request, sizeof (request))
 	       != sizeof (request)) ) {
 		jack_error ("cannot send request type %d to server",
 				    request.type);
@@ -1592,7 +1616,7 @@
 	while( 1 ) {
 		jack_uuid_t uid;
 
-		if (read (client->request_fd, &uid, sizeof (uid)) != sizeof (uid)) {
+		if (read_retry (client->request_fd, &uid, sizeof (uid)) != sizeof (uid)) {
 			jack_error ("cannot read result for request type %d from"
 					" server (%s)", request.type, strerror (errno));
 			goto out;
@@ -1613,19 +1637,19 @@
 			break;
                 }
 
-		if (read (client->request_fd, (char *)retval[num_replies-1].client_name, JACK_CLIENT_NAME_SIZE) 
+		if (read_retry (client->request_fd, (char *)retval[num_replies-1].client_name, JACK_CLIENT_NAME_SIZE) 
 			       	!= JACK_CLIENT_NAME_SIZE) {
 			jack_error ("cannot read result for request type %d from"
 					" server (%s)", request.type, strerror (errno));
 			goto out;
 		}
-		if (read (client->request_fd, (char *)retval[num_replies-1].command, JACK_PORT_NAME_SIZE)
+		if (read_retry (client->request_fd, (char *)retval[num_replies-1].command, JACK_PORT_NAME_SIZE)
 			       	!= JACK_PORT_NAME_SIZE) {
 			jack_error ("cannot read result for request type %d from"
 					" server (%s)", request.type, strerror (errno));
 			goto out;
 		}
-		if (read (client->request_fd, & retval[num_replies-1].flags, sizeof(retval[num_replies-1].flags) )
+		if (read_retry (client->request_fd, & retval[num_replies-1].flags, sizeof(retval[num_replies-1].flags) )
 			       	!= sizeof(retval[num_replies-1].flags) ) {
 			jack_error ("cannot read result for request type %d from"
 					" server (%s)", request.type, strerror (errno));
@@ -1742,7 +1766,7 @@
 		/* server has sent us an event. process the
 		 * event and reply */
 		
-		if (read (client->event_fd, &event, sizeof (event))
+		if (read_retry (client->event_fd, &event, sizeof (event))
 		    != sizeof (event)) {
 			jack_error ("cannot read server event (%s)",
 				    strerror (errno));
@@ -1751,7 +1775,7 @@
 
                 if (event.type == PropertyChange) {
                         key = (char *) malloc (event.y.key_size);
-                        if (read (client->event_fd, key, event.y.key_size) != 
+                        if (read_retry (client->event_fd, key, event.y.key_size) != 
                             event.y.key_size) {
                                 jack_error ("cannot read property change key (%s)",
                                             strerror (errno));
@@ -1868,7 +1892,7 @@
 		DEBUG ("client has dealt with the event, writing "
 		       "response on event fd");
 		
-		if (write (client->event_fd, &status, sizeof (status))
+		if (write_retry (client->event_fd, &status, sizeof (status))
 		    != sizeof (status)) {
 			jack_error ("cannot send event response to "
 				    "engine (%s)", strerror (errno));
@@ -1888,7 +1912,7 @@
 	int pret = 0;
 	char c = 0;
 
-	if (write (client->graph_next_fd, &c, sizeof (c))
+	if (write_retry (client->graph_next_fd, &c, sizeof (c))
 	    != sizeof (c)) {
 		DEBUG("cannot write byte to fd %d", client->graph_next_fd);
 		jack_error ("cannot continue execution of the "
@@ -1916,7 +1940,7 @@
 	}
 
 	if (pret > 0 && (pfds[0].revents & POLLIN)) {
-		if (read (client->graph_wait_fd, &c, sizeof (c))
+		if (read_retry (client->graph_wait_fd, &c, sizeof (c))
 		    != sizeof (c)) {
 			jack_error ("cannot complete execution of the "
 				"processing graph (%s)", strerror(errno));
