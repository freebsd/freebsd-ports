--- Modules/Debuggers/ProjectCenter/PTYView.m.orig	2013-02-09 22:42:13.000000000 +0800
+++ Modules/Debuggers/ProjectCenter/PTYView.m	2015-01-22 22:51:16.258350353 +0800
@@ -30,7 +30,7 @@
 #include <fcntl.h>
 #include <sys/types.h>
 
-#if defined (__FreeBSD__)
+#if defined (__FreeBSD__) || defined (__DragonFly__)
 #include <sys/ioctl.h>
 #include <termios.h>
 #include <libutil.h>
@@ -61,7 +61,9 @@
 #endif
 
 
-#if !(defined (__NetBSD__)) && !(defined (__SOLARIS__)) && !(defined (__OpenBSD__)) && !(defined(__FreeBSD__))
+#if !(defined (__NetBSD__)) && !(defined (__SOLARIS__)) \
+ && !(defined (__OpenBSD__)) && !(defined(__FreeBSD__)) \
+ && !defined(__DragonFly__)
 #  include <pty.h>
 #endif
 
