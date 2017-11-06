--- src/nvim/os/pty_process_unix.c.orig	2017-05-04 05:10:42 UTC
+++ src/nvim/os/pty_process_unix.c
@@ -12,7 +12,7 @@
 #include <sys/ioctl.h>
 
 // forkpty is not in POSIX, so headers are platform-specific
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined (__DragonFly__)
 # include <libutil.h>
 #elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__)
 # include <util.h>
