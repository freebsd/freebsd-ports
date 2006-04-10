--- plugins/wav/wav.cpp.orig	Wed Jun 15 06:15:18 2005
+++ plugins/wav/wav.cpp	Wed Sep 14 17:30:30 2005
@@ -34,7 +34,10 @@
 #ifdef WIN32
 #include <winsock.h>
 #else
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <sys/param.h>
 #endif
 