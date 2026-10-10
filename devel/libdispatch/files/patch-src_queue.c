--- src/queue.c.orig	2026-05-01 02:25:26 UTC
+++ src/queue.c
@@ -7036,7 +7036,7 @@ _dispatch_runloop_root_queue_wakeup_4CF(dispatch_queue
 	_dispatch_runloop_queue_wakeup(upcast(dq)._dl, 0, false);
 }
 
-#if TARGET_OS_MAC || defined(_WIN32) || defined(__OpenBSD__)
+#if TARGET_OS_MAC || defined(_WIN32) || defined(__OpenBSD__) || defined(__FreeBSD__)
 dispatch_runloop_handle_t
 _dispatch_runloop_root_queue_get_port_4CF(dispatch_queue_t dq)
 {
