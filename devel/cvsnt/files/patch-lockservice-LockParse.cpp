--- lockservice/LockParse.cpp.orig	Sun Jan 25 20:42:06 2004
+++ lockservice/LockParse.cpp	Sun Jan 25 20:42:39 2004
@@ -5,6 +5,7 @@
 #include <winsock2.h>
 #include <ws2tcpip.h>
 #else
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netdb.h>
 #include <errno.h>
