--- src/http.cpp.orig	2026-09-04 20:46:41 UTC
+++ src/http.cpp
@@ -819,9 +819,9 @@ Connection::set_keepalive(uint32_t seconds)
 #endif
 #else
     // Linux based systems
-    setsockopt(socket, SOL_TCP, TCP_KEEPIDLE, &seconds, sizeof(uint32_t));
-    setsockopt(socket, SOL_TCP, TCP_KEEPINTVL, &interval, sizeof(uint32_t));
-    setsockopt(socket, SOL_TCP, TCP_KEEPCNT, &cnt, sizeof(uint32_t));
+    setsockopt(socket, IPPROTO_TCP, TCP_KEEPIDLE, &seconds, sizeof(uint32_t));
+    setsockopt(socket, IPPROTO_TCP, TCP_KEEPINTVL, &interval, sizeof(uint32_t));
+    setsockopt(socket, IPPROTO_TCP, TCP_KEEPCNT, &cnt, sizeof(uint32_t));
 #endif
 #endif
 }
