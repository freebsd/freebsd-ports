--- assa/IPv4Socket.cpp.orig	Mon Mar 29 12:01:10 2004
+++ assa/IPv4Socket.cpp	Mon Mar 29 12:02:18 2004
@@ -151,7 +151,7 @@
 	  are not guaranteed to be aligned correctly!!!
 	*/
 	trace_with_mask("IPv4Socket::accept",SOCKTRACE);
-	size_t length = 0;
+	socklen_t length = 0;
 	int new_fd = -1;
 	SA* remote_address;
 
