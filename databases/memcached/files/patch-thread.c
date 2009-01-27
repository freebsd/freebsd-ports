--- thread.c.orig	2009-01-27 00:34:19.000000000 -0200
+++ thread.c	2009-01-27 00:34:04.000000000 -0200
@@ -644,6 +644,7 @@
         perror("Can't allocate thread descriptors");
         exit(1);
     }
+    memset(threads, 0, sizeof(LIBEVENT_THREAD) * nthreads);
 
     threads[0].base = main_base;
     threads[0].thread_id = pthread_self();
