
$FreeBSD$

--- src/TcpSocket.cpp.orig	Sat Jul 20 18:37:06 2002
+++ src/TcpSocket.cpp	Sat Aug 10 14:09:52 2002
@@ -81,6 +81,9 @@
 #error need sys/time.h
 #endif
 
+#ifndef MSG_NOSIGNAL
+#define MSG_NOSIGNAL 0
+#endif
 
 #include "Util.h"
 #include "Exception.h"
