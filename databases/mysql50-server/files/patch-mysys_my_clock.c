--- mysys/my_clock.c.orig	2010-01-15 10:48:59.000000000 +0100
+++ mysys/my_clock.c	2010-10-26 12:29:27.000000000 +0200
@@ -16,6 +16,9 @@
 #define USES_TYPES
 #include "my_global.h"
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#endif
 #if !defined(_MSC_VER) && !defined(__BORLANDC__) && !defined(OS2) && !defined(__NETWARE__)
 #include "mysys_priv.h"
 #include <sys/times.h>
@@ -23,6 +26,11 @@
 
 long my_clock(void)
 {
+#if defined(__FreeBSD__) && __FreeBSD_version__ >= 700000
+  struct timespec ts;
+  clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts);
+  return (ts.tv_sec * CLK_TCK + ts.tv_nsec / (1000000000 / CLK_TCK));
+#else
 #if !defined(MSDOS) && !defined(__WIN__) && !defined(OS2) && !defined(__NETWARE__)
   struct tms tmsbuf;
   VOID(times(&tmsbuf));
@@ -30,4 +38,5 @@
 #else
   return clock();
 #endif
+#endif
 }
