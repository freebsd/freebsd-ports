--- rxvt/_rxvtlib.h.orig	2017-07-14 16:03:54 UTC
+++ rxvt/_rxvtlib.h
@@ -128,7 +128,7 @@
 #ifdef TTY_GID_SUPPORT
 # include <grp.h>
 #endif
-#ifdef PTYS_ARE_PTMX
+#if defined(PTYS_ARE_PTMX) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 # include <sys/resource.h>	/* for struct rlimit */
 # include <sys/stropts.h>	/* for I_PUSH */
 #endif
