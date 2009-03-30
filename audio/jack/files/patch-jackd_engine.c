--- jackd/engine.c.orig	2008-12-02 17:29:23.000000000 +0100
+++ jackd/engine.c	2009-02-11 20:38:52.000000000 +0100
@@ -1383,7 +1383,7 @@
 	if ((r = read (client->request_fd, &req, sizeof (req)))
 	    < (ssize_t) sizeof (req)) {
 		if (r == 0) {
-#ifdef JACK_USE_MACH_THREADS
+#ifndef __linux
 			/* poll is implemented using
 			   select (see the macosx/fakepoll
 			   code). When the socket is closed
@@ -1396,7 +1396,7 @@
 			   and remove the client.
 			*/
 			jack_mark_client_socket_error (engine, fd);
-#endif /* JACK_USE_MACH_THREADS */
+#endif /* !__linux */
 			return 1;
 		} else {
 			jack_error ("cannot read request from client (%d/%d/%s)",
