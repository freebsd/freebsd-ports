--- src/ptytty.c.orig	Thu Jan 22 18:16:16 2004
+++ src/ptytty.c	Mon Feb  2 15:12:59 2004
@@ -41,7 +41,7 @@
 #ifdef HAVE_SYS_IOCTL_H
 # include <sys/ioctl.h>
 #endif
-#if defined(PTYS_ARE_PTMX) && !defined(__CYGWIN32__)
+#if defined(PTYS_ARE_PTMX) && !defined(__CYGWIN32__) && !defined(__FreeBSD__)
 # include <sys/stropts.h>      /* for I_PUSH */
 #endif
 
