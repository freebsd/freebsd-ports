--- src/xvc_server.cpp.orig	2026-10-18 09:11:29 UTC
+++ src/xvc_server.cpp
@@ -10,6 +10,7 @@
 #include <errno.h>
 #include <netinet/tcp.h>
 #include <unistd.h>
+#include <sys/socket.h> // for send
 
 #include <cstring>
 #include <stdexcept>
