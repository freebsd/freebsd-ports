--- lib/IMProto.c.orig	2002-10-03 18:35:28.000000000 +0900
+++ lib/IMProto.c	2008-11-02 01:12:32.000000000 +0900
@@ -259,7 +259,7 @@
 #ifdef IM_TCP_TRANSPORT
     if (ipw->imp.use_tcp_transport) {
 	ipw->imp.tcp_port = 0;	/* let the system choose the port number */
-	ipw->imp.tcp_sock = IMCreateTCPService(&ipw->imp.tcp_port);
+	ipw->imp.tcp_sock = IMCreateTCPService(&ipw->imp.tcp_port, "127.0.0.1");
     }
     if (ipw->imp.tcp_sock >= 0) {
 	TRACE(("call XtAppAddInput for tcp socket(%d)\n", ipw->imp.tcp_sock));
