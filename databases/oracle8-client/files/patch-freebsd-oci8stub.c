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
@@ -119,6 +120,14 @@
 
 int __l_sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
 
+struct l_sockaddr {
+	u_int16_t sa_family;
+	char sa_data[14];
+};
+
+int __l_connect(int s, const struct l_sockaddr *l_sa, socklen_t addrlen);
+int __l_sigaction(int signum, const struct sigaction *l_act, struct sigaction *oldact);
+
 #ifdef stdin
 #undef stdin
 #undef stdout
@@ -528,3 +537,27 @@ __l_sigprocmask(int l_how, const sigset_
 
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
+
+int 
+__l_sigaction(int signum, const struct sigaction *l_act, struct sigaction *oldact)
+{
+	struct sigaction act;
+
+	act.sa_handler = l_act->sa_handler;
+	act.sa_flags = l_act->sa_flags & (SA_ONSTACK | SA_RESTART | SA_RESETHAND |
+		SA_NOCLDSTOP | SA_NODEFER | SA_NOCLDWAIT | SA_SIGINFO);
+	act.sa_mask = l_act->sa_mask;
+	return sigaction(signum, &act, oldact);
+}
+
