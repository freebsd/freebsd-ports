--- Top/csound.c.orig	2011-10-16 22:59:03.000000000 +0900
+++ Top/csound.c	2011-12-07 01:15:33.000000000 +0900
@@ -60,10 +60,13 @@
 #include "cs_par_dispatch.h"
 #include "csound_orc_semantics.h"
 
-#if defined(linux) || defined(__HAIKU__)
+#if defined(linux) || defined(__HAIKU__) || defined(__FreeBSD__)
 #define PTHREAD_SPINLOCK_INITIALIZER 0
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/sysctl.h>
+#endif
 #if defined(USE_OPENMP)
 #include <omp.h>
 #endif /* USE_OPENMP */
@@ -899,7 +902,7 @@
 
 #if defined(ANDROID) || (!defined(LINUX) && !defined(SGI) && \
                          !defined(__HAIKU__) && !defined(__BEOS__) && \
-                         !defined(__MACH__))
+                         !defined(__MACH__) && !defined(__FreeBSD__))
 static char *signal_to_string(int sig)
 {
     switch(sig) {
@@ -3172,7 +3175,7 @@
 /* ------------------------------------ */
 
 #if defined(HAVE_RDTSC)
-#if !(defined(LINUX) && defined(__GNUC__) && defined(__i386__))
+#if !(defined(LINUX) && defined(__GNUC__) && defined(__i386__)) || !(defined(__FreeBSD__) && defined(__i386__))
 #undef HAVE_RDTSC
 #endif
 #endif
@@ -3185,6 +3188,13 @@
 static int getTimeResolution(void)
 {
 #if defined(HAVE_RDTSC)
+#if defined(__FreeBSD__)
+    size_t size;
+    int timeResolutionSeconds;
+    size = sizeof timeResolutionSeconds;
+    sysctlbyname("hw.clockrate", &timeResolutionSeconds, &size, NULL, 0);
+
+#else
     FILE    *f;
     char    buf[256];
 
@@ -3220,9 +3230,14 @@
       }
     }
     fclose(f);
+#endif /* __FreeBSD__ */
     if (UNLIKELY(timeResolutionSeconds <= 0.0)) {
       fprintf(stderr, Str("No valid CPU frequency entry "
+#if defined(__FreeBSD__)
+                          "was found.\n"));
+#else
                           "was found in /proc/cpuinfo.\n"));
+#endif /* __FreeBSD__ */
       return -1;
     }
     /* MHz -> seconds */
