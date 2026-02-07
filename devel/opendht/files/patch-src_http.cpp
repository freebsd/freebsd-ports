--- src/http.cpp.orig	2024-08-11 15:44:47 UTC
+++ src/http.cpp
@@ -707,9 +707,9 @@ Connection::set_keepalive(uint32_t seconds)
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
