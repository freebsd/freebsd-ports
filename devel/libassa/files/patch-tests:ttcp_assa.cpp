--- tests/ttcp_assa.cpp.orig	Fri Jan  7 10:46:12 2005
+++ tests/ttcp_assa.cpp	Tue Mar 22 16:32:30 2005
@@ -91,7 +91,7 @@
 IPv4Socket* sock = 0;		// Communication socket
 
 struct sockaddr_in peer;
-int peerlen;
+socklen_t peerlen;
 
 int domain, fromlen;
 int fd;				/* fd of network socket */
@@ -775,7 +775,7 @@
 Nread( int fd_, void* buf_, int count )
 {
     struct sockaddr_in from;
-    int len = sizeof(from);
+    socklen_t len = sizeof(from);
     register int cnt;
 
     if( udp )  
