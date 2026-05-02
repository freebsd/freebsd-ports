--- src/butil/compat.h.orig	2026-02-23 02:11:29 UTC
+++ src/butil/compat.h
@@ -66,6 +66,10 @@ __END_DECLS
 
 #include <sys/epoll.h>
 
+#elif defined(OS_FREEBSD)
+
+#include <sys/event.h>
+
 #else
 
 #error "The platform does not support epoll-like APIs"
@@ -81,6 +85,8 @@ inline uint64_t pthread_numeric_id() {
         return id;
     }
     return -1;
+#elif defined(OS_FREEBSD)
+    return (uint64_t)(uintptr_t)pthread_self();
 #else
     return pthread_self();
 #endif
