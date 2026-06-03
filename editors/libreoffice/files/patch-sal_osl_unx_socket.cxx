--- sal/osl/unx/socket.cxx.orig	2026-02-05 22:14:25 UTC
+++ sal/osl/unx/socket.cxx
@@ -40,7 +40,7 @@
 #include <fcntl.h>
 #include <netdb.h>
 #ifdef FREEBSD
-#include <netinet/ip.h>
+#include <netinet/in.h>
 #endif
 #include <netinet/tcp.h>
 #include <poll.h>
