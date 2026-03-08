--- src/xvc_server.cpp.orig	2026-03-02 17:34:32 UTC
+++ src/xvc_server.cpp
@@ -9,6 +9,7 @@
 #include <errno.h>
 #include <netinet/tcp.h>
 #include <unistd.h>
+#include <sys/socket.h> // for send
 
 #include <cstring>
 #include <stdexcept>
