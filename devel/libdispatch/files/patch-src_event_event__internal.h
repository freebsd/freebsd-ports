--- src/event/event_internal.h.orig	2026-05-01 02:25:26 UTC
+++ src/event/event_internal.h
@@ -127,6 +127,8 @@ typedef uintptr_t dispatch_unote_ident_t;
 typedef uintptr_t dispatch_unote_ident_t;
 #elif defined(__OpenBSD__)
 typedef uintptr_t dispatch_unote_ident_t;
+#elif defined(__FreeBSD__)
+typedef uintptr_t dispatch_unote_ident_t;
 #else
 typedef uint32_t dispatch_unote_ident_t;
 #endif
