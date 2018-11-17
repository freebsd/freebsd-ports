--- Top/csound.c.orig	2018-11-07 14:05:23 UTC
+++ Top/csound.c
@@ -60,10 +60,14 @@
 //#include "cs_par_dispatch.h"
 #include "find_opcode.h"
 
-#if defined(linux)||defined(__HAIKU__)|| defined(__EMSCRIPTEN__)||defined(__CYGWIN__)
+#if defined(linux) || defined(__FreeBSD__) || defined(__HAIKU__)|| defined(__EMSCRIPTEN__)||defined(__CYGWIN__)
 #define PTHREAD_SPINLOCK_INITIALIZER 0
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/sysctl.h>
+#endif
+
 #include "csound_standard_types.h"
 
 #include "csdebug.h"
@@ -405,7 +409,7 @@ static const CSOUND cenviron_ = {
     rewriteheader,
     csoundLoadSoundFile,
     fdrecord,
-    fdclose,
+    fd__close,
     csoundCreateFileHandle,
     csoundGetFileName,
     csoundFileClose,
@@ -3755,7 +3759,7 @@ void csoundNotifyFileOpened(CSOUND* csou
 /* ------------------------------------ */
 
 #if defined(HAVE_RDTSC)
-#if !(defined(LINUX) && defined(__GNUC__) && defined(__i386__))
+#if !(defined(LINUX) && defined(__GNUC__) && defined(__i386__)) || !(defined(__FreeBSD__) && defined(__i386__))
 #undef HAVE_RDTSC
 #endif
 #endif
@@ -3768,6 +3772,13 @@ static double timeResolutionSeconds = -1
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
 
@@ -3803,9 +3814,14 @@ static int getTimeResolution(void)
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
