--- plugins/vorbis/vorbis.cpp.orig	Tue Jun 28 13:03:06 2005
+++ plugins/vorbis/vorbis.cpp	Wed Sep 14 17:34:12 2005
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
 
