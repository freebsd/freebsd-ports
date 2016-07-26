--- Top/csound.c.orig	2013-01-07 12:49:34 UTC
+++ Top/csound.c
@@ -70,11 +70,14 @@ extern "C" {
  **** MAJOR PROBLEM: PTHREAD_SPINLOCK_INITIALIZER is not defined in
       Linux or Haiku */
 
-#if defined(linux) || defined(__HAIKU__)
+#if defined(linux) || defined(__HAIKU__) || defined(__FreeBSD__)
 #define PTHREAD_SPINLOCK_INITIALIZER 0
 #endif
 #endif /* PARCS */
 
+#if defined(__FreeBSD__)
+#include <sys/sysctl.h>
+#endif
 #if defined(USE_OPENMP)
 #include <omp.h>
 #endif /* USE_OPENMP */
@@ -430,7 +433,7 @@ extern "C" {
     NULL,           /*  csRandState         */
     0,              /*  randSeed1           */
     0,              /*  randSeed2           */
-#if defined(HAVE_PTHREAD_SPIN_LOCK) && (defined(PARCS))
+#if defined(__GNUC__) && defined(HAVE_PTHREAD_SPIN_LOCK) && (defined(PARCS))
     PTHREAD_SPINLOCK_INITIALIZER,              /*  memlock           */
 #else
     0,              /*  memlock             */
@@ -2914,7 +2917,7 @@ void csoundNotifyFileOpened(CSOUND *csou
 /* ------------------------------------ */
 
 #if defined(HAVE_RDTSC)
-#if !(defined(LINUX) && defined(__GNUC__) && defined(__i386__))
+#if !(defined(LINUX) && defined(__GNUC__) && defined(__i386__)) || !(defined(LINUX) && defined(__i386__))
 #undef HAVE_RDTSC
 #endif
 #endif
@@ -2927,6 +2930,12 @@ static double timeResolutionSeconds = -1
 static int getTimeResolution(void)
 {
 #if defined(HAVE_RDTSC)
+#if defined(__FreeBSD__)
+    size_t size;
+    int timeResolutionSeconds;
+    size = sizeof timeResolutionSeconds;
+    sysctlbyname("hw.clockrate", &timeResolutionSeconds, &size, NULL, 0);
+#else
     FILE    *f;
     char    buf[256];
 
@@ -2967,9 +2976,14 @@ static int getTimeResolution(void)
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
