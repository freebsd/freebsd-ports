--- Top/csound.c.old	2011-01-30 01:43:37.000000000 -0600
+++ Top/csound.c	2011-01-30 01:46:42.000000000 -0600
@@ -58,7 +58,9 @@
 #include "namedins.h"
 #include "pvfileio.h"
 #include "fftlib.h"
-
+#if defined(__FreeBSD__)
+#include <sys/sysctl.h>
+#endif
 #if defined(USE_OPENMP)
 #include <omp.h>
 #endif
@@ -2641,49 +2643,14 @@
     static int getTimeResolution(void)
     {
 #if defined(HAVE_RDTSC)
-        FILE    *f;
-        char    buf[256];
+     size_t size;
+     int timeResolutionSeconds;
+     size = sizeof timeResolutionSeconds;
+     sysctlbyname("hw.clockrate", &timeResolutionSeconds, &size, NULL, 0);
 
-        /* if frequency is not known yet */
-        f = fopen("/proc/cpuinfo", "r");
-        if (UNLIKELY(f == NULL)) {
-            fprintf(stderr, Str("Cannot open /proc/cpuinfo. "
-                    "Support for RDTSC is not available.\n"));
-            return -1;
-        }
-        /* find CPU frequency */
-        while (fgets(buf, 256, f) != NULL) {
-            int     i;
-            char    *s = (char*) buf - 1;
-
-            buf[255] = '\0';          /* safety */
-            if (strlen(buf) < 9) {
-                continue;    /* too short, skip */
-            }
-            while (*++s != '\0')
-                if (isupper(*s)) {
-                    *s = tolower(*s);    /* convert to lower case */
-                }
-            if (strncmp(buf, "cpu mhz", 7) != 0) {
-                continue;    /* check key name */
-            }
-            s = strchr(buf, ':');             /* find frequency value */
-            if (s == NULL) {
-                continue;    /* invalid entry */
-            }
-            do {
-                s++;
-            } while (*s == ' ' || *s == '\t');    /* skip white space */
-            i = sscanf(s, "%lf", &timeResolutionSeconds);
-            if (i < 1 || timeResolutionSeconds < 1.0) {
-                timeResolutionSeconds = -1.0;       /* invalid entry */
-                continue;
-            }
-        }
-        fclose(f);
         if (UNLIKELY(timeResolutionSeconds <= 0.0)) {
             fprintf(stderr, Str("No valid CPU frequency entry "
-                    "was found in /proc/cpuinfo.\n"));
+                    "was found.\n"));
             return -1;
         }
         /* MHz -> seconds */
