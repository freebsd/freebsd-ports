--- private/private.h.orig	2021-09-17 04:54:52 UTC
+++ private/private.h
@@ -177,7 +177,7 @@ void _dispatch_prohibit_transition_to_multithreaded(bo
 
 #if TARGET_OS_MAC
 #define DISPATCH_COCOA_COMPAT 1
-#elif defined(__linux__) || defined(__FreeBSD__) || defined(_WIN32)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(_WIN32)
 #define DISPATCH_COCOA_COMPAT 1
 #else
 #define DISPATCH_COCOA_COMPAT 0
@@ -191,6 +191,8 @@ typedef int dispatch_runloop_handle_t;
 typedef mach_port_t dispatch_runloop_handle_t;
 #elif defined(__linux__) || defined(__FreeBSD__)
 typedef int dispatch_runloop_handle_t;
+#elif defined(__unix__)
+typedef uint64_t dispatch_runloop_handle_t;
 #elif defined(_WIN32)
 typedef void *dispatch_runloop_handle_t;
 #else
