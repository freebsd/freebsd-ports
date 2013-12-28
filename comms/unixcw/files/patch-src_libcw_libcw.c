--- src/libcw/libcw.c.orig	2013-07-15 14:27:57.000000000 -0500
+++ src/libcw/libcw.c	2013-07-15 17:28:22.000000000 -0500
@@ -43,15 +43,9 @@
    - Section:Global variables
 */
 
-
 #include "config.h"
 
 
-#define _BSD_SOURCE   /* usleep() */
-#define _POSIX_SOURCE /* sigaction() */
-#define _POSIX_C_SOURCE 200112L /* pthread_sigmask() */
-
-
 #include <sys/time.h>
 #include <sys/ioctl.h>
 #include <sys/types.h>
@@ -84,7 +78,6 @@
 # include <strings.h>
 #endif
 
-
 /* http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=403043 */
 #if defined(NSIG)             /* Debian GNU/Linux: signal.h; Debian kFreeBSD: signal.h (libc0.1-dev_2.13-21_kfreebsd-i386.deb) */
 #define CW_SIG_MAX (NSIG)
@@ -92,10 +85,17 @@
 #define CW_SIG_MAX (_NSIG)
 #elif defined(RTSIG_MAX)      /* Debian GNU/Linux: linux/limits.h */
 #define CW_SIG_MAX ((RTSIG_MAX)+1)
+#elif defined(__FreeBSD__)
+#define CW_SIG_MAX (_SIG_MAXSIG)
 #else
 #error "unknown number of signals"
 #endif
 
+#ifndef __FreeBSD__
+#define _BSD_SOURCE   /* usleep() */
+#define _POSIX_SOURCE /* sigaction() */
+#define _POSIX_C_SOURCE 200112L /* pthread_sigmask() */
+#endif
 
 
 #if defined(BSD)
