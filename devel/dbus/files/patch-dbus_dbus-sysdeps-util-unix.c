--- dbus/dbus-sysdeps-util-unix.c.orig	2008-12-21 14:51:17.000000000 -0500
+++ dbus/dbus-sysdeps-util-unix.c	2008-12-21 14:51:37.000000000 -0500
@@ -38,6 +38,7 @@
 #include <stdio.h>
 #include <errno.h>
 #include <fcntl.h>
+#include <syslog.h>
 #include <sys/stat.h>
 #include <grp.h>
 #include <sys/socket.h>
