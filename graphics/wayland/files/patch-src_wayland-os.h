--- src/wayland-os.h.orig	2015-07-06 19:38:51 UTC
+++ src/wayland-os.h
@@ -30,13 +30,25 @@ int
 wl_os_socket_cloexec(int domain, int type, int protocol);
 
 int
+wl_os_socketpair_cloexec(int domain, int type, int protocol, int sv[2]);
+
+int
 wl_os_dupfd_cloexec(int fd, long minfd);
 
 ssize_t
 wl_os_recvmsg_cloexec(int sockfd, struct msghdr *msg, int flags);
 
+/* FIXME? not sure if this will work in this header like this ...
+   though seems build only header perhaps? */
+#ifdef HAVE_SYS_EPOLL_H
 int
 wl_os_epoll_create_cloexec(void);
+#endif
+
+#ifdef HAVE_SYS_EVENT_H
+int
+wl_os_kqueue_create_cloexec(void);
+#endif
 
 int
 wl_os_accept_cloexec(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
