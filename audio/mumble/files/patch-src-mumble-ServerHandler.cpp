--- src/mumble/ServerHandler.cpp.orig	2014-08-08 15:51:59 UTC
+++ src/mumble/ServerHandler.cpp
@@ -46,6 +46,12 @@
 #include "RichTextEditor.h"
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
