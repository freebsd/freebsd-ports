--- tricky/accept.c.orig	2007-12-13 00:45:25.000000000 +0100
+++ tricky/accept.c	2007-12-13 00:46:50.000000000 +0100
@@ -22,7 +22,7 @@
 int	port;
 struct sockaddr_in myAddr;
 struct sockaddr_in *remAddr;
-int     remAddrSize=0;
+socklen_t remAddrSize=0;
 pthread_attr_t attr, *attrPtr = &attr;
 
 RegisterThread("Arbiter","Manages the client and server communication",TRUE);
