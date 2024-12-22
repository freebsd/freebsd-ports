Obtained from:	https://github.com/curl/curl/commit/ff5091aa9f73802e894b1cbdf24ab84e103200e2

--- lib/asyn-thread.c.orig	2024-12-11 07:08:12 UTC
+++ lib/asyn-thread.c
@@ -195,9 +195,11 @@ void destroy_thread_sync_data(struct thread_sync_data 
    * close one end of the socket pair (may be done in resolver thread);
    * the other end (for reading) is always closed in the parent thread.
    */
+#ifndef USE_EVENTFD
   if(tsd->sock_pair[1] != CURL_SOCKET_BAD) {
     wakeup_close(tsd->sock_pair[1]);
   }
+#endif
 #endif
   memset(tsd, 0, sizeof(*tsd));
 }
