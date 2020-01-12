--- Top/csound.c.orig	2020-01-11 09:18:32 UTC
+++ Top/csound.c
@@ -61,10 +61,14 @@
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
@@ -3773,7 +3777,7 @@ void csoundNotifyFileOpened(CSOUND* csound, const char
 /* ------------------------------------ */
 
 #if defined(HAVE_RDTSC)
-#if !(defined(LINUX) && defined(__GNUC__) && defined(__i386__))
+#if !(defined(LINUX) && defined(__GNUC__) && defined(__i386__)) || !(defined(__FreeBSD__) && defined(__i386__))
 #undef HAVE_RDTSC
 #endif
 #endif
@@ -3786,6 +3790,13 @@ static double timeResolutionSeconds = -1.0;
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
 
@@ -3821,9 +3832,14 @@ static int getTimeResolution(void)
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
