--- ./Sources/Network/Socket/unix_socket.cpp.orig	2011-01-27 05:27:59.000000000 -0500
+++ ./Sources/Network/Socket/unix_socket.cpp	2012-10-06 21:26:11.000000000 -0400
@@ -39,7 +39,7 @@
 #include <netinet/tcp.h>
 #include <errno.h>
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 # define SOL_TCP IPPROTO_TCP    // Fix for BSD systems. --NDT
 #endif
 
@@ -140,6 +140,7 @@
 
 void CL_UnixSocket::set_keep_alive(bool enable, int timeout, int interval)
 {
+#if !(defined(__APPLE__) || defined(__FreeBSD__))
 	int value = enable ? 1 : 0;
 	int result = setsockopt(handle, SOL_SOCKET, SO_KEEPALIVE, (const char *) &value, sizeof(int));
 	throw_if_failed(result);
@@ -149,6 +150,7 @@
 		setsockopt(handle, SOL_TCP, TCP_KEEPIDLE, (const char *) &timeout, sizeof(int));
 		setsockopt(handle, SOL_TCP, TCP_KEEPINTVL, (const char *) &interval, sizeof(int));
 	}
+#endif
 }
 
 void CL_UnixSocket::bind(const CL_SocketName &socketname, bool reuse_address)
