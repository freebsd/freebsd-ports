--- src/mumble11x/ServerHandler.cpp.orig	2010-01-08 00:37:46.000000000 +0200
+++ src/mumble11x/ServerHandler.cpp	2010-01-11 00:01:42.000000000 +0200
@@ -39,6 +39,12 @@
 #include "Database.h"
 #include "PacketDataStream.h"
 #include "NetworkConfig.h"
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <netinet/tcp.h>
+#endif
 
 ServerHandlerMessageEvent::ServerHandlerMessageEvent(QByteArray &msg, bool flush) : QEvent(static_cast<QEvent::Type>(SERVERSEND_EVENT)) {
 	qbaMsg = msg;
