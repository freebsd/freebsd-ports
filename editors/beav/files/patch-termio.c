--- termio.c.orig	Sat Jul 21 22:35:05 2001
+++ termio.c	Thu Mar 21 03:52:16 2002
@@ -12,6 +12,9 @@
 #include    <signal.h>
 #ifdef BSD
 #include    <sys/ioctl.h>
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#include <sys/ioctl_compat.h>
+#endif
 #else
 #ifdef OS2
 #ifndef __EMX__
