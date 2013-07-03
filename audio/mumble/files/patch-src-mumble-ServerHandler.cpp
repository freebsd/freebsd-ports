--- src/mumble/ServerHandler.cpp.orig	2013-06-04 11:44:15.381594007 -0500
+++ src/mumble/ServerHandler.cpp	2013-06-04 11:44:36.772583833 -0500
@@ -45,6 +45,12 @@
 #include "PacketDataStream.h"
 #include "SSL.h"
 #include "User.h"
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <netinet/tcp.h>
+#endif
 
 ServerHandlerMessageEvent::ServerHandlerMessageEvent(const QByteArray &msg, unsigned int mtype, bool flush) : QEvent(static_cast<QEvent::Type>(SERVERSEND_EVENT)) {
 	qbaMsg = msg;
