--- tests/os-wrappers-test.c.orig	2017-08-08 18:20:52 UTC
+++ tests/os-wrappers-test.c
@@ -26,6 +26,8 @@
 
 #define _GNU_SOURCE
 
+#include "../config.h"
+
 #include <stdlib.h>
 #include <stdint.h>
 #include <assert.h>
@@ -73,15 +75,22 @@ socket(int domain, int type, int protocol)
 {
 	wrapped_calls_socket++;
 
+#ifdef SOCK_CLOEXEC
 	if (fall_back && (type & SOCK_CLOEXEC)) {
 		errno = EINVAL;
 		return -1;
 	}
+#endif
 
 	return real_socket(domain, type, protocol);
 }
 
 __attribute__ ((visibility("default"))) int
+#ifdef fcntl
+/* Work around #define fcntl in epoll-shim */
+#define old_fcntl fcntl
+#undef fcntl
+#endif
 fcntl(int fd, int cmd, ...)
 {
 	va_list ap;
@@ -89,10 +98,12 @@ fcntl(int fd, int cmd, ...)
 
 	wrapped_calls_fcntl++;
 
+#ifdef F_DUPFD_CLOEXEC
 	if (fall_back && (cmd == F_DUPFD_CLOEXEC)) {
 		errno = EINVAL;
 		return -1;
 	}
+#endif
 
 	va_start(ap, cmd);
 	arg = va_arg(ap, void*);
@@ -100,16 +111,21 @@ fcntl(int fd, int cmd, ...)
 
 	return real_fcntl(fd, cmd, arg);
 }
+#ifdef old_fcntl
+#define fcntl old_fcntl 
+#endif
 
 __attribute__ ((visibility("default"))) ssize_t
 recvmsg(int sockfd, struct msghdr *msg, int flags)
 {
 	wrapped_calls_recvmsg++;
 
+#ifdef MSG_CMSG_CLOEXEC
 	if (fall_back && (flags & MSG_CMSG_CLOEXEC)) {
 		errno = EINVAL;
 		return -1;
 	}
+#endif
 
 	return real_recvmsg(sockfd, msg, flags);
 }
@@ -156,12 +172,14 @@ TEST(os_wrappers_socket_cloexec)
 	do_os_wrappers_socket_cloexec(0);
 }
 
+#ifdef SOCK_CLOEXEC
 TEST(os_wrappers_socket_cloexec_fallback)
 {
 	/* forced fallback */
 	init_fallbacks(1);
 	do_os_wrappers_socket_cloexec(1);
 }
+#endif
 
 static void
 do_os_wrappers_dupfd_cloexec(int n)
@@ -195,11 +213,13 @@ TEST(os_wrappers_dupfd_cloexec)
 	do_os_wrappers_dupfd_cloexec(0);
 }
 
+#ifdef F_DUPFD_CLOEXEC
 TEST(os_wrappers_dupfd_cloexec_fallback)
 {
 	init_fallbacks(1);
 	do_os_wrappers_dupfd_cloexec(3);
 }
+#endif
 
 struct marshal_data {
 	struct wl_connection *read_connection;
@@ -218,8 +238,7 @@ struct marshal_data {
 static void
 setup_marshal_data(struct marshal_data *data)
 {
-	assert(socketpair(AF_UNIX,
-			  SOCK_STREAM | SOCK_CLOEXEC, 0, data->s) == 0);
+	assert(wl_os_socketpair_cloexec(AF_UNIX, SOCK_STREAM, 0, data->s) == 0);
 
 	data->read_connection = wl_connection_create(data->s[0]);
 	assert(data->read_connection);
@@ -328,11 +347,13 @@ TEST(os_wrappers_recvmsg_cloexec)
 	do_os_wrappers_recvmsg_cloexec(0);
 }
 
+#ifdef MSG_CMSG_CLOEXEC
 TEST(os_wrappers_recvmsg_cloexec_fallback)
 {
 	init_fallbacks(1);
 	do_os_wrappers_recvmsg_cloexec(1);
 }
+#endif
 
 static void
 do_os_wrappers_epoll_create_cloexec(int n)
