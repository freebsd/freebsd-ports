--- lockservice/server.cpp.orig	Thu Mar 13 04:28:10 2003
+++ lockservice/server.cpp	Tue Feb  3 11:35:11 2004
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
@@ -162,7 +165,7 @@
 #ifdef _WIN32
 		int addrlen;
 #else
-		size_t addrlen;
+		socklen_t addrlen;
 #endif
  		int maxdesc = -1;
 
