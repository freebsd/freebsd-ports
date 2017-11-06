--- jackd/engine.c.orig	2016-09-14 17:41:53 UTC
+++ jackd/engine.c
@@ -1435,7 +1435,7 @@ handle_external_client_request (jack_eng
 	if ((r = read (client->request_fd, &req, sizeof(req)))
 	    < (ssize_t)sizeof(req)) {
 		if (r == 0) {
-#if defined(JACK_USE_MACH_THREADS) || defined(__OpenBSD__)
+#if 1
 			/* poll is implemented using
 			   select (see the macosx/fakepoll
 			   code). When the socket is closed
