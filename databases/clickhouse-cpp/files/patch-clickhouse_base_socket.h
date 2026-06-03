--- clickhouse/base/socket.h.orig	2025-09-20 19:59:03 UTC
+++ clickhouse/base/socket.h
@@ -18,6 +18,10 @@
 #   include <sys/socket.h>
 #   include <poll.h>
 
+#   if defined(__FreeBSD__)
+#       include <netinet/in.h>
+#    endif
+
 #   if !defined(SOCKET)
 #       define SOCKET int
 #   endif
