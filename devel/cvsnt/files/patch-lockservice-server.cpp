--- lockservice/server.cpp.orig	Sun Jan 25 20:42:11 2004
+++ lockservice/server.cpp	Sun Jan 25 20:42:29 2004
@@ -8,7 +8,10 @@
 #include <ws2tcpip.h>
 #define SOCKET_ERRNO WSAGetLastError()
 #else
+#include <sys/types.h>
+#include <sys/time.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <errno.h>
 #include <unistd.h>
