--- src/http.cpp.orig	2022-11-06 06:49:51 UTC
+++ src/http.cpp
@@ -608,9 +608,9 @@ Connection::async_connect(std::vector<asio::ip::tcp::e
             setsockopt(socket, IPPROTO_TCP, TCP_KEEPALIVE, &start, sizeof(uint32_t));
 #else
             // Linux based systems
-            setsockopt(socket, SOL_TCP, TCP_KEEPIDLE, &start, sizeof(uint32_t));
-            setsockopt(socket, SOL_TCP, TCP_KEEPINTVL, &interval, sizeof(uint32_t));
-            setsockopt(socket, SOL_TCP, TCP_KEEPCNT, &cnt, sizeof(uint32_t));
+            setsockopt(socket, IPPROTO_TCP, TCP_KEEPIDLE, &start, sizeof(uint32_t));
+            setsockopt(socket, IPPROTO_TCP, TCP_KEEPINTVL, &interval, sizeof(uint32_t));
+            setsockopt(socket, IPPROTO_TCP, TCP_KEEPCNT, &cnt, sizeof(uint32_t));
 #endif
 #endif
         }
