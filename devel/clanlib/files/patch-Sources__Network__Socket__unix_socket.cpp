--- ./Sources/Network/Socket/unix_socket.cpp.orig	2012-09-25 07:45:17.000000000 -0400
+++ ./Sources/Network/Socket/unix_socket.cpp	2012-09-25 08:00:41.000000000 -0400
@@ -39,7 +39,7 @@
 #include <netinet/tcp.h>
 #include <errno.h>
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 # define SOL_TCP IPPROTO_TCP    // Fix for BSD systems. --NDT
 #endif
 
@@ -140,7 +140,7 @@
 
 void CL_UnixSocket::set_keep_alive(bool enable, int timeout, int interval)
 {
-#ifndef __APPLE__
+#if !(defined(__APPLE__) || defined(__FreeBSD__))
 	int value = enable ? 1 : 0;
 	int result = setsockopt(handle, SOL_SOCKET, SO_KEEPALIVE, (const char *) &value, sizeof(int));
 	throw_if_failed(result);
