--- jackd/engine.c.orig	2013-11-30 17:04:00 UTC
+++ jackd/engine.c
@@ -1415,7 +1415,7 @@ handle_external_client_request (jack_eng
 	if ((r = read (client->request_fd, &req, sizeof (req)))
 	    < (ssize_t) sizeof (req)) {
 		if (r == 0) {
-#ifdef JACK_USE_MACH_THREADS
+#ifndef __linux
 			/* poll is implemented using
 			   select (see the macosx/fakepoll
 			   code). When the socket is closed
@@ -1428,7 +1428,7 @@ handle_external_client_request (jack_eng
 			   and remove the client.
 			*/
 			jack_mark_client_socket_error (engine, fd);
-#endif /* JACK_USE_MACH_THREADS */
+#endif /* !__linux */
 			return 1;
 		} else {
 			jack_error ("cannot read request from client (%d/%d/%s)",
