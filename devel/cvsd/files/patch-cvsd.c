diff -urN /usr/ports/devel/cvsd/files/patch-cvsd.c devel/cvsd/files/patch-cvsd.c
--- /usr/ports/devel/cvsd/files/patch-cvsd.c	Thu Jan  1 09:00:00 1970
+++ devel/cvsd/files/patch-cvsd.c	Tue Sep 17 19:26:39 2002
@@ -0,0 +1,12 @@
+--- cvsd.c.orig	Sun Aug 25 09:44:33 2002
++++ cvsd.c	Tue Sep 17 19:26:31 2002
+@@ -60,7 +60,9 @@
+ #include <sys/wait.h>
+ #include <sys/socket.h>
+ #include <sys/time.h>
++#ifndef __FreeBSD__
+ #include <netinet/in.h>
++#endif
+ #include <arpa/inet.h>
+ #ifdef HAVE_NETDB_H
+ #include <netdb.h>
