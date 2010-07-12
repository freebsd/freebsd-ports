--- plugins/wav/wav.cpp.orig	2006-11-18 12:51:46.000000000 +0200
+++ plugins/wav/wav.cpp	2010-06-07 10:36:19.157879953 +0300
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
 
