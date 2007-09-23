--- Top/csound.c.orig	2007-06-03 04:03:48.000000000 +0200
+++ Top/csound.c	2007-09-10 00:52:03.000000000 +0200
@@ -54,6 +54,7 @@
 #include "namedins.h"
 #include "pvfileio.h"
 #include "fftlib.h"
+#include <sys/sysctl.h>
 
 extern void MakeAscii(CSOUND *, WINDAT *, const char *);
 extern void DrawAscii(CSOUND *, WINDAT *);
@@ -2444,46 +2445,17 @@
   static int getTimeResolution(void)
   {
 #if defined(HAVE_RDTSC)
-    FILE    *f;
-    char    buf[256];
+		size_t size;
+		int timeResolutionSeconds;
+		size = sizeof timeResolutionSeconds;
+		sysctlbyname("hw.clockrate", &timeResolutionSeconds, &size, NULL, 0);
 
-    /* if frequency is not known yet */
-    f = fopen("/proc/cpuinfo", "r");
-    if (f == NULL) {
-      fprintf(stderr, "Cannot open /proc/cpuinfo. "
-                      "Support for RDTSC is not available.\n");
-      return -1;
-    }
-    /* find CPU frequency */
-    while (fgets(buf, 256, f) != NULL) {
-      int     i;
-      char    *s = (char*) buf - 1;
-
-      buf[255] = '\0';          /* safety */
-      if (strlen(buf) < 9)
-        continue;                       /* too short, skip */
-      while (*++s != '\0')
-        if (isupper(*s))
-          *s = tolower(*s);             /* convert to lower case */
-      if (strncmp(buf, "cpu mhz", 7) != 0)
-        continue;                       /* check key name */
-      s = strchr(buf, ':');             /* find frequency value */
-      if (s == NULL) continue;              /* invalid entry */
-      do {
-        s++;
-      } while (*s == ' ' || *s == '\t');    /* skip white space */
-      i = sscanf(s, "%lf", &timeResolutionSeconds);
-      if (i < 1 || timeResolutionSeconds < 1.0) {
-        timeResolutionSeconds = -1.0;       /* invalid entry */
-        continue;
-      }
-    }
-    fclose(f);
-    if (timeResolutionSeconds <= 0.0) {
+		if (timeResolutionSeconds <= 0.0) {
       fprintf(stderr, "No valid CPU frequency entry "
-                      "was found in /proc/cpuinfo.\n");
+                      "was found.\n");
       return -1;
     }
+		
     /* MHz -> seconds */
     timeResolutionSeconds = 0.000001 / timeResolutionSeconds;
 #elif defined(WIN32)
