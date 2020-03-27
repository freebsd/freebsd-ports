--- dbus/dbus-sysdeps-util-unix.c.orig	2019-06-09 12:08:49 UTC
+++ dbus/dbus-sysdeps-util-unix.c
@@ -42,6 +42,7 @@
 #include <stdio.h>
 #include <errno.h>
 #include <fcntl.h>
+#include <syslog.h>
 #include <sys/stat.h>
 #ifdef HAVE_SYS_RESOURCE_H
 #include <sys/resource.h>
