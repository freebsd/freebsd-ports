--- net/socket/tcp_socket_posix.cc.orig	2025-06-30 07:04:30 UTC
+++ net/socket/tcp_socket_posix.cc
@@ -99,6 +99,17 @@ bool SetTCPKeepAlive(int fd, bool enable, int delay) {
       PLOG(ERROR) << "Failed to set TCP_KEEPALIVE on fd: " << fd;
       return false;
     }
+#elif BUILDFLAG(IS_FREEBSD)
+  // Set seconds until first TCP keep alive.
+  if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &delay, sizeof(delay))) {
+    PLOG(ERROR) << "Failed to set TCP_KEEPIDLE on fd: " << fd;
+    return false;
+  }
+  // Set seconds between TCP keep alives.  
+  if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPINTVL, &delay, sizeof(delay))) {
+    PLOG(ERROR) << "Failed to set TCP_KEEPINTVL on fd: " << fd;
+    return false;
+  }
 #endif
   }
 
