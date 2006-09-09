--- dcf77/audioin.c.orig	Sun Jul 30 12:00:54 2006
+++ dcf77/audioin.c	Sun Jul 30 12:05:07 2006
@@ -45,6 +45,9 @@
 #include <stropts.h>
 #endif
 #ifdef HAVE_SYS_CONF_H
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
 #include <sys/conf.h>
 #endif
 
@@ -52,7 +55,12 @@
 #include <sys/mman.h>
 #include <sched.h>
 #include <sys/soundcard.h>
+#ifdef __linux__
 #include <endian.h>
+#endif
+#ifdef __FreeBSD__ 
+#include <sys/endian.h>
+#endif
 #endif
 
 #include "dcf77.h"
