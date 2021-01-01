--- lib/Basics/socket-utils.h.orig	2017-11-15 11:23:07 UTC
+++ lib/Basics/socket-utils.h
@@ -31,6 +31,12 @@
 #include <WS2tcpip.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif
+
 ////////////////////////////////////////////////////////////////////////////////
 /// @brief socket types
 ////////////////////////////////////////////////////////////////////////////////
