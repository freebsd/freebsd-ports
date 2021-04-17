--- server/red-stream.cpp.orig	2021-04-21 06:29:28 UTC
+++ server/red-stream.cpp
@@ -24,6 +24,7 @@
 #include <netdb.h>
 #include <sys/socket.h>
 #include <netinet/tcp.h>
+#include <netinet/in.h>
 #else
 #include <ws2tcpip.h>
 #endif
