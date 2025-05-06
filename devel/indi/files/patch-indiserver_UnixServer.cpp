--- indiserver/UnixServer.cpp.orig	2025-03-31 09:12:20 UTC
+++ indiserver/UnixServer.cpp
@@ -25,6 +25,7 @@
 #include <sys/un.h>
 #include <sys/socket.h>
 #include <fcntl.h>
+#include <unistd.h>
 #ifdef ENABLE_INDI_SHARED_MEMORY
 
 std::string UnixServer::unixSocketPath = INDIUNIXSOCK;
