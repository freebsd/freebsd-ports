--- src/server/master.cc.orig	2022-07-12 01:57:55 UTC
+++ src/server/master.cc
@@ -448,7 +448,11 @@ int Server::start_master_thread() {
     if (!single_thread) {
         pthread_barrier_wait(&reactor_thread_barrier);
     }
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+    SW_START_SLEEP;
+#else
     pthread_barrier_wait(&gs->manager_barrier);
+#endif
 #else
     SW_START_SLEEP;
 #endif
@@ -850,8 +854,10 @@ int Server::create() {
 #ifdef HAVE_PTHREAD_BARRIER
     if (is_process_mode()) {
         pthread_barrier_init(&reactor_thread_barrier, nullptr, reactor_num + 1);
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
         pthread_barrierattr_setpshared(&gs->manager_barrier_attr, PTHREAD_PROCESS_SHARED);
         pthread_barrier_init(&gs->manager_barrier, &gs->manager_barrier_attr, 2);
+#endif
     }
 #endif
 
@@ -983,8 +989,10 @@ void Server::destroy() {
 #ifdef HAVE_PTHREAD_BARRIER
     if (is_process_mode()) {
         pthread_barrier_destroy(&reactor_thread_barrier);
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
         pthread_barrier_destroy(&gs->manager_barrier);
         pthread_barrierattr_destroy(&gs->manager_barrier_attr);
+#endif
     }
 #endif
     sw_shm_free(session_list);
