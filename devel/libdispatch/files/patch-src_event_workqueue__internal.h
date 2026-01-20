--- src/event/workqueue_internal.h.orig	2025-03-07 00:50:44 UTC
+++ src/event/workqueue_internal.h
@@ -30,7 +30,7 @@ void _dispatch_workq_worker_unregister(dispatch_queue_
 void _dispatch_workq_worker_register(dispatch_queue_global_t root_q);
 void _dispatch_workq_worker_unregister(dispatch_queue_global_t root_q);
 
-#if defined(__linux__) || defined(_WIN32)
+#if defined(__linux__) || defined(_WIN32) || defined(__FreeBSD__)
 #define HAVE_DISPATCH_WORKQ_MONITORING 1
 #else
 #define HAVE_DISPATCH_WORKQ_MONITORING 0
