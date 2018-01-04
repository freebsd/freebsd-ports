--- src/wayland-os.c.orig	2017-08-08 18:20:52 UTC
+++ src/wayland-os.c
@@ -25,6 +25,8 @@
 
 #define _GNU_SOURCE
 
+#include "../config.h"
+
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <unistd.h>
@@ -32,7 +34,6 @@
 #include <errno.h>
 #include <sys/epoll.h>
 
-#include "../config.h"
 #include "wayland-os.h"
 
 static int
@@ -62,26 +63,50 @@ wl_os_socket_cloexec(int domain, int type, int protoco
 {
 	int fd;
 
+#ifdef SOCK_CLOEXEC
 	fd = socket(domain, type | SOCK_CLOEXEC, protocol);
 	if (fd >= 0)
 		return fd;
 	if (errno != EINVAL)
 		return -1;
+#endif
 
 	fd = socket(domain, type, protocol);
 	return set_cloexec_or_close(fd);
 }
 
 int
+wl_os_socketpair_cloexec(int domain, int type, int protocol, int sv[2])
+{
+       int retval;
+
+#ifdef SOCK_CLOEXEC
+       retval = socketpair(domain, type | SOCK_CLOEXEC, protocol, sv);
+       if (retval >= 0)
+               return retval;
+       if (errno != EINVAL)
+               return -1;
+#endif
+
+       retval = socketpair(domain, type, protocol, sv);
+       if (set_cloexec_or_close(sv[0]) < 0 || set_cloexec_or_close(sv[1]) < 0)
+               retval = -1;
+
+       return retval;
+}
+
+int
 wl_os_dupfd_cloexec(int fd, long minfd)
 {
 	int newfd;
 
+#ifdef F_DUPFD_CLOEXEC
 	newfd = fcntl(fd, F_DUPFD_CLOEXEC, minfd);
 	if (newfd >= 0)
 		return newfd;
 	if (errno != EINVAL)
 		return -1;
+#endif
 
 	newfd = fcntl(fd, F_DUPFD, minfd);
 	return set_cloexec_or_close(newfd);
@@ -123,15 +148,18 @@ wl_os_recvmsg_cloexec(int sockfd, struct msghdr *msg, 
 {
 	ssize_t len;
 
+#ifdef MSG_CMSG_CLOEXEC
 	len = recvmsg(sockfd, msg, flags | MSG_CMSG_CLOEXEC);
 	if (len >= 0)
 		return len;
 	if (errno != EINVAL)
 		return -1;
+#endif
 
 	return recvmsg_cloexec_fallback(sockfd, msg, flags);
 }
 
+#ifdef HAVE_SYS_EPOLL_H
 int
 wl_os_epoll_create_cloexec(void)
 {
@@ -148,6 +176,7 @@ wl_os_epoll_create_cloexec(void)
 	fd = epoll_create(1);
 	return set_cloexec_or_close(fd);
 }
+#endif
 
 int
 wl_os_accept_cloexec(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
