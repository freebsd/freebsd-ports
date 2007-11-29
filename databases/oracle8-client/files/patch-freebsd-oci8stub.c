--- freebsd/oci8stub.c.orig	2007-11-11 12:25:01.000000000 +0600
+++ freebsd/oci8stub.c	2007-11-28 05:03:13.000000000 +0600
@@ -2,6 +2,7 @@
 #include <sys/param.h>
 #include <sys/stat.h>
 #include <sys/resource.h>
+#include <sys/socket.h>
 #include <assert.h>
 #include <errno.h>
 #include <dlfcn.h>
@@ -119,6 +120,13 @@
 
 int __l_sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
 
+struct l_sockaddr {
+	u_int16_t sa_family;
+	char sa_data[14];
+};
+
+int __l_connect(int s, const struct l_sockaddr *l_sa, socklen_t addrlen);
+
 #ifdef stdin
 #undef stdin
 #undef stdout
@@ -528,3 +536,14 @@
 
 	return sigprocmask(how, set, oldset);
 }
+
+int
+__l_connect(int s, const struct l_sockaddr *l_sa, socklen_t addrlen)
+{
+	struct sockaddr sa;
+
+	memcpy(sa.sa_data, l_sa->sa_data, sizeof(sa.sa_data));
+	sa.sa_len = addrlen;
+	sa.sa_family = l_sa->sa_family;
+	return connect(s, &sa, addrlen);
+}
