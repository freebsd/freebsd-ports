--- src/mumble/ServerHandler.cpp.orig	2010-01-08 00:37:46.000000000 +0200
+++ src/mumble/ServerHandler.cpp	2010-01-10 23:57:24.000000000 +0200
@@ -42,6 +42,12 @@
 #include "NetworkConfig.h"
 #include "OSInfo.h"
 #include "SSL.h"
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <netinet/tcp.h>
+#endif
 
 ServerHandlerMessageEvent::ServerHandlerMessageEvent(const QByteArray &msg, unsigned int mtype, bool flush) : QEvent(static_cast<QEvent::Type>(SERVERSEND_EVENT)) {
 	qbaMsg = msg;
