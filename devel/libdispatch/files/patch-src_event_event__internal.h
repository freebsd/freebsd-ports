--- src/event/event_internal.h.orig	2021-09-17 04:54:52 UTC
+++ src/event/event_internal.h
@@ -125,6 +125,8 @@ typedef uintptr_t dispatch_unote_ident_t;
 
 #if defined(_WIN32)
 typedef uintptr_t dispatch_unote_ident_t;
+#elif defined(__FreeBSD__)
+typedef uintptr_t dispatch_unote_ident_t;
 #else
 typedef uint32_t dispatch_unote_ident_t;
 #endif
