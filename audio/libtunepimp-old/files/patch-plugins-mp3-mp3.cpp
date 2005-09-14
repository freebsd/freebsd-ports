--- plugins/mp3/mp3.cpp.orig	Tue Jul 12 06:44:06 2005
+++ plugins/mp3/mp3.cpp	Wed Sep 14 17:32:42 2005
@@ -33,7 +33,10 @@
 #ifdef WIN32
 #include <winsock.h>
 #else
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <sys/param.h>
 #endif
 
