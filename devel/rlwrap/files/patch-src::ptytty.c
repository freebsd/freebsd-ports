--- src/ptytty.c.orig	Mon Oct 31 16:01:11 2005
+++ src/ptytty.c	Mon Oct 31 16:01:57 2005
@@ -41,7 +41,7 @@
 #ifdef HAVE_SYS_IOCTL_H
 # include <sys/ioctl.h>
 #endif
-#if defined(PTYS_ARE_PTMX) && !defined(__CYGWIN32__)
+#if defined(PTYS_ARE_PTMX) && !defined(__CYGWIN32__) && !defined(__FreeBSD__)
 # include <sys/stropts.h>	/* for I_PUSH */
 #endif
 
