--- clickhouse/base/socket.cpp.orig	2025-09-20 19:59:03 UTC
+++ clickhouse/base/socket.cpp
@@ -355,7 +355,7 @@ void Socket::SetTcpKeepAlive(int idle, int intvl, int 
 
 #if defined(_unix_)
     setsockopt(handle_, SOL_SOCKET, SO_KEEPALIVE, &val, sizeof(val));
-#   if defined(_linux_)
+#   if defined(_linux_) || defined(_freebsd_)
         setsockopt(handle_, IPPROTO_TCP, TCP_KEEPIDLE, &idle, sizeof(idle));
 #   elif defined(_darwin_)
         setsockopt(handle_, IPPROTO_TCP, TCP_KEEPALIVE, &idle, sizeof(idle));
