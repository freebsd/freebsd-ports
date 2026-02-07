--- cpucycles/wrapper.c.orig	2025-12-26 09:44:50 UTC
+++ cpucycles/wrapper.c
@@ -18,6 +18,12 @@
 #include <inttypes.h>
 #include <signal.h>
 #include <setjmp.h>
+
+#ifdef __FreeBSD__
+#include <sched.h>
+#include <sys/sysctl.h>
+#endif
+
 #include "cpucycles.h"
 #include "cpucycles_internal.h"
 
@@ -83,6 +89,21 @@ static double osfreq(void)
     if (s > 0) return result;
   }
 
+#ifdef __FreeBSD__
+  {
+    int freq;
+    size_t len = sizeof freq;
+    char *freqctl;
+
+    if (asprintf(&freqctl, "dev.cpu.%d.freq", sched_getcpu())) {
+      if (sysctlbyname(freqctl, &freq, &len, NULL, 0) == 0) {
+        free(freqctl);
+        return 1e6 * freq;
+      } else
+        free(freqctl);
+    }
+  }
+#else
   f = fopen("/sys/devices/system/cpu/cpu0/cpufreq/scaling_setspeed", "r");
   if (f) {
     s = fscanf(f,"%lf",&result);
@@ -165,6 +186,7 @@ static double osfreq(void)
     pclose(f);
     if (result) return 1000000.0 * result;
   }
+#endif /* defined(__FreeBSD__) */
 
   x = getenv("cpucyclespersecond");
   if (x) {
