--- tests/ttcp_assa.cpp.orig	Wed Dec 24 17:39:58 2003
+++ tests/ttcp_assa.cpp	Wed Dec 24 17:41:13 2003
@@ -91,7 +91,7 @@
 IPv4Socket* sock = 0;		// Communication socket
 
 struct sockaddr_in peer;
-int peerlen;
+socklen_t peerlen;
 
 int domain, fromlen;
 int fd;				/* fd of network socket */
@@ -384,7 +384,7 @@
 	}
 #else
 	if (getpeername(fd, (struct sockaddr*) &peer, 
-			(int*) &peerlen) < 0) {
+			&peerlen) < 0) {
 	    err("getpeername");
 	}
 #endif /* defined(_POSIX_SOURCE) */
@@ -783,7 +783,7 @@
 Nread( int fd_, void* buf_, int count )
 {
     struct sockaddr_in from;
-    int len = sizeof(from);
+    socklen_t len = sizeof(from);
     register int cnt;
 
     if( udp )  
@@ -795,7 +795,7 @@
 #else  // _POSIX_SOURCE
 	cnt = recvfrom( fd_, (char*) buf_, count, 0, 
 			(struct sockaddr*) &from, 
-			(int*) &len );
+			&len );
 #endif
 	numCalls++;
     } else {
