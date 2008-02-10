--- rts/System/Net/UDPSocket.h.orig	2007-12-26 15:43:52.000000000 +0300
+++ rts/System/Net/UDPSocket.h	2008-01-10 23:39:09.000000000 +0300
@@ -7,6 +7,7 @@
 #ifdef _WIN32
 #include "Platform/Win/win32.h"
 #else
+#include <sys/socket.h>
 #include <netinet/in.h>
 #endif
 
