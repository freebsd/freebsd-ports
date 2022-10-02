--- src/server/manager.cc.orig	2022-07-12 01:57:55 UTC
+++ src/server/manager.cc
@@ -247,7 +247,11 @@ void Manager::start(Server *_server) {
 #endif
 
 #ifdef HAVE_PTHREAD_BARRIER
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+    SW_START_SLEEP;
+#else
     pthread_barrier_wait(&_server->gs->manager_barrier);
+#endif
 #else
     SW_START_SLEEP;
 #endif
