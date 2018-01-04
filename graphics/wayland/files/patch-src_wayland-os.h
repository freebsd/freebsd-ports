--- src/wayland-os.h.orig	2017-08-08 18:20:52 UTC
+++ src/wayland-os.h
@@ -30,6 +30,9 @@ int
 wl_os_socket_cloexec(int domain, int type, int protocol);
 
 int
+wl_os_socketpair_cloexec(int domain, int type, int protocol, int sv[2]);
+
+int
 wl_os_dupfd_cloexec(int fd, long minfd);
 
 ssize_t
