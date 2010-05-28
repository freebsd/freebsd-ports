--- rxvt/_rxvtlib.h.orig	2010-05-26 21:25:41.000000000 -0400
+++ rxvt/_rxvtlib.h	2010-05-26 21:39:11.000000000 -0400
@@ -128,7 +128,7 @@
 #ifdef TTY_GID_SUPPORT
 # include <grp.h>
 #endif
-#ifdef PTYS_ARE_PTMX
+#if defined(PTYS_ARE_PTMX) && !defined(__FreeBSD__)
 # include <sys/resource.h>	/* for struct rlimit */
 # include <sys/stropts.h>	/* for I_PUSH */
 #endif
