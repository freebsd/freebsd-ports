Index: lib/IMProto.c
===================================================================
RCS file: /home/cvs/private/hrs/kinput2/lib/IMProto.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
--- lib/IMProto.c.orig	2002-10-03 09:35:28 UTC
+++ lib/IMProto.c
@@ -259,7 +259,7 @@ Cardinal *num_args;
 #ifdef IM_TCP_TRANSPORT
     if (ipw->imp.use_tcp_transport) {
 	ipw->imp.tcp_port = 0;	/* let the system choose the port number */
-	ipw->imp.tcp_sock = IMCreateTCPService(&ipw->imp.tcp_port);
+	ipw->imp.tcp_sock = IMCreateTCPService(&ipw->imp.tcp_port, "localhost");
     }
     if (ipw->imp.tcp_sock >= 0) {
 	TRACE(("call XtAppAddInput for tcp socket(%d)\n", ipw->imp.tcp_sock));
@@ -281,7 +281,7 @@ Cardinal *num_args;
 	 * The unix domain socket pathname has the following form:
 	 *   <UNIX_SOCKET_DIR>/<Display Name>-<Language>
 	 */
-	(void)mkdir(UNIX_SOCKET_DIR, 0777);
+	(void)mkdir(UNIX_SOCKET_DIR, 01777);
 #ifdef S_IFLNK
 	{
 	    /*
@@ -292,11 +292,11 @@ Cardinal *num_args;
 	    struct stat st;
 	    if (lstat(UNIX_SOCKET_DIR, &st) == 0 &&
 		(st.st_mode & S_IFMT) == S_IFDIR) {
-		(void)chmod(UNIX_SOCKET_DIR, 0777);
+		(void)chmod(UNIX_SOCKET_DIR, 01777);
 	    }
 	}
 #else
-	(void)chmod(UNIX_SOCKET_DIR, 0777);
+	(void)chmod(UNIX_SOCKET_DIR, 01777);
 #endif
 	(void)sprintf(path, "%s/%s", UNIX_SOCKET_DIR,
 		      DisplayString(XtDisplay(new)));
