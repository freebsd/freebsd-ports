--- Modules/Debuggers/ProjectCenter/PTYView.m.orig	2012-04-20 08:35:30.000000000 +0000
+++ Modules/Debuggers/ProjectCenter/PTYView.m
@@ -30,7 +30,7 @@
 #include <fcntl.h>
 #include <sys/types.h>
 
-#if defined (__FreeBSD__)
+#if defined (__FreeBSD__) || defined (__DragonFly__)
 #include <sys/ioctl.h>
 #include <termios.h>
 #include <libutil.h>
@@ -42,7 +42,8 @@
 #include <stdlib.h>
 #include <string.h>
 
-#if !defined(__OpenBSD__) && !defined(__FreeBSD__) && !(defined (__NetBSD__))
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__) \
+ && !defined (__NetBSD__) && !defined(__DragonFly__)
 #include <stropts.h>
 #endif
 
@@ -56,7 +57,9 @@
 #define USE_FORKPTY_REPLACEMENT 1
 #endif
 
-#if !(defined (__NetBSD__)) && !(defined (__SOLARIS__)) && !(defined (__OpenBSD__)) && !(defined(__FreeBSD__))
+#if !(defined (__NetBSD__)) && !(defined (__SOLARIS__)) \
+ && !(defined (__OpenBSD__)) && !(defined(__FreeBSD__)) \
+ && !defined(__DragonFly__)
 #  include <pty.h>
 #endif
 
