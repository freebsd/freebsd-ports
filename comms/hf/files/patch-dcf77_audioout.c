--- dcf77/audioout.c.orig	Sun Jul 30 12:05:54 2006
+++ dcf77/audioout.c	Sun Jul 30 12:06:52 2006
@@ -44,6 +44,9 @@
 #include <stropts.h>
 #endif
 #ifdef HAVE_SYS_CONF_H
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
 #include <sys/conf.h>
 #endif
 
@@ -51,7 +54,12 @@
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
