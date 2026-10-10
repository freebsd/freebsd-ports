--- src/shims/lock.h.orig	2026-05-01 02:25:26 UTC
+++ src/shims/lock.h
@@ -214,6 +214,9 @@ _dispatch_lock_has_failed_trylock(dispatch_lock lock_v
 #elif defined(__OpenBSD__)
 #define HAVE_FUTEX 1
 #define HAVE_FUTEX_PI 0
+#elif defined(__FreeBSD__)
+#define HAVE_FUTEX 0
+#define HAVE_FUTEX_PI 0
 #else
 #define HAVE_FUTEX 0
 #define HAVE_FUTEX_PI 0
