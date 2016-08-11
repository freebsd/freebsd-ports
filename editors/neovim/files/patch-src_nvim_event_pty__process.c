--- src/nvim/event/pty_process.c.orig	2016-04-25 01:46:34 UTC
+++ src/nvim/event/pty_process.c
@@ -10,7 +10,7 @@
 #include <sys/ioctl.h>
 
 // forkpty is not in POSIX, so headers are platform-specific
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined __DragonFly__
 # include <libutil.h>
 #elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__)
 # include <util.h>
