--- lib/cloexec.h.orig	2012-03-26 20:25:19.000000000 +0200
+++ lib/cloexec.h	2013-05-06 23:36:45.087537539 +0200
@@ -22,6 +22,7 @@
 #ifndef _WIN32
 #include <sys/types.h> 
 #include <sys/socket.h>
+#include <sys/param.h>
 #include <fcntl.h>
 static __inline void fcntl_cloexec(socket_t fd)
 {
@@ -55,7 +56,7 @@
 static __inline socket_t accept_cloexec(socket_t sockfd, struct sockaddr *addr,
 				      socklen_t *addrlen)
 {
-#ifdef SOCK_CLOEXEC
+#if defined(SOCK_CLOEXEC) && __FreeBSD_version > 1000032
 	return accept4(sockfd, addr, addrlen, SOCK_CLOEXEC);
 #else
 	socket_t fd = accept(sockfd, addr, addrlen);
