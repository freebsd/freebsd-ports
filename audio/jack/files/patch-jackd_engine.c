--- jackd/engine.c.orig	Wed Dec  6 23:40:20 2006
+++ jackd/engine.c	Wed Dec  6 23:40:58 2006
@@ -1444,7 +1444,7 @@
 				    (engine, pfd[i].fd)) {
 					jack_error ("could not handle external"
 						    " client request");
-#ifdef JACK_USE_MACH_THREADS
+#if 1
                                     /* poll is implemented using
 				       select (see the macosx/fakepoll
 				       code). When the socket is closed
