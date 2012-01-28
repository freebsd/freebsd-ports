--- Top/csound.c.orig	2011-10-16 22:59:03.000000000 +0900
+++ Top/csound.c	2011-12-07 01:15:33.000000000 +0900
@@ -67,11 +67,14 @@
 
   /* **** MAJOR PROBLEM: PTHREAD_SPINLOCK_INITIALIZER is not defined in Linux */
 
-#ifdef linux
+#if defined(linux) || defined(__FreeBSD__)
   #define PTHREAD_SPINLOCK_INITIALIZER 0
 #endif
 #endif /* PARCS */
 
+#if defined(__FreeBSD__)
+#include <sys/sysctl.h>
+#endif
 #if defined(USE_OPENMP)
 #include <omp.h>
 #endif /* USE_OPENMP */
@@ -383,7 +386,7 @@
     0.0,            /*  curBeat             */
     0.0,            /*  curBeat_inc         */
     0.0,            /*  beatTime            */
-#if defined(HAVE_PTHREAD_SPIN_LOCK) && defined(PARCS)
+#if defined(__GNUC__) && defined(HAVE_PTHREAD_SPIN_LOCK) && defined(PARCS)
     PTHREAD_SPINLOCK_INITIALIZER,              /*  spoutlock           */
     PTHREAD_SPINLOCK_INITIALIZER,              /*  spinlock            */
 #else
@@ -2854,7 +2857,7 @@
   /* ------------------------------------ */
 
 #if defined(HAVE_RDTSC)
-#if !(defined(LINUX) && defined(__GNUC__) && defined(__i386__))
+#if !(defined(LINUX) && defined(__GNUC__) && defined(__i386__)) || !(defined(__FreeBSD__) && defined(__i386__))
 #undef HAVE_RDTSC
 #endif
 #endif
@@ -2867,6 +2870,13 @@
   static int getTimeResolution(void)
   {
 #if defined(HAVE_RDTSC)
+#if defined(__FreeBSD__)
+      size_t size;
+      int timeResolutionSeconds;
+      size = sizeof timeResolutionSeconds;
+      sysctlbyname("hw.clockrate", &timeResolutionSeconds, &size, NULL, 0);
+
+#else
       FILE    *f;
       char    buf[256];
 
@@ -2923,9 +2933,14 @@
         }
       }
       fclose(f);
+#endif /* __FreeBSD__ */
       if (UNLIKELY(timeResolutionSeconds <= 0.0)) {
         fprintf(stderr, Str("No valid CPU frequency entry "
+#if defined(__FreeBSD__)
+                            "was found.\n"));
+#else
                             "was found in /proc/cpuinfo.\n"));
+#endif /* __FreeBSD__ */
         return -1;
       }
       /* MHz -> seconds */
