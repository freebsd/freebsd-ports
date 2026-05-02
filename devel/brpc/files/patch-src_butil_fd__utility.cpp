--- src/butil/fd_utility.cpp.orig	2026-02-23 02:11:29 UTC
+++ src/butil/fd_utility.cpp
@@ -24,7 +24,7 @@
 #include <sys/socket.h>              // setsockopt
 #include <netinet/tcp.h>             // TCP_NODELAY
 #include <netinet/tcp.h>
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 #include <netinet/tcp_fsm.h>        // TCPS_ESTABLISHED, TCP6S_ESTABLISHED
 #endif
 #include "butil/logging.h"
@@ -88,6 +88,17 @@ int is_connected(int sockfd) {
         return -1;
     }
     if (ti.tcpi_state != TCP_ESTABLISHED) {
+        errno = ENOTCONN;
+        return -1;
+    }
+#elif defined(OS_FREEBSD)
+    struct tcp_info ti{};
+    socklen_t len = sizeof(ti);
+    if (getsockopt(sockfd, IPPROTO_TCP, TCP_INFO, &ti, &len) < 0) {
+        PLOG(FATAL) << "Fail to getsockopt";
+        return -1;
+    }
+    if (ti.tcpi_state != TCPS_ESTABLISHED) {
         errno = ENOTCONN;
         return -1;
     }
