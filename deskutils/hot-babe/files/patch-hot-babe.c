--- hot-babe.c.orig	Wed Aug 25 16:20:50 2004
+++ hot-babe.c	Sat Nov  6 19:41:41 2004
@@ -26,6 +26,13 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
+#ifdef __FreeBSD__
+#include <sys/time.h>
+#include <sys/resource.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/dkstat.h>
+#endif
 
 /* x11 includes */
 #include <gdk/gdk.h>
@@ -69,14 +76,34 @@
 static int system_cpu(void)
 {
   unsigned int  cpuload;
+  int           i;
+#ifdef __linux__
   u_int64_t     load, total, oload, ototal;
   u_int64_t     ab, ac, ad, ae;
-  int           i;
   FILE         *stat;
+#endif
+#ifdef __FreeBSD__
+  long load, total, oload, ototal;
+  long ab, ac, ad, ae;
+  long cp_time[CPUSTATES];
+  size_t len = sizeof(cp_time);
+#endif
 
+#ifdef __linux__
   stat = fopen("/proc/stat", "r");
   fscanf(stat, "%*s %Ld %Ld %Ld %Ld", &ab, &ac, &ad, &ae);
   fclose(stat);
+#endif
+#ifdef __FreeBSD__
+  if (sysctlbyname("kern.cp_time", &cp_time, &len, NULL, 0) < 0)
+	  (void)fprintf(stderr, "Cannot get kern.cp_time");
+	       
+  ab = cp_time[CP_USER];
+  ac = cp_time[CP_NICE];
+  ad = cp_time[CP_SYS];
+  ae = cp_time[CP_IDLE];
+#endif
+	  
 
   /* Find out the CPU load */
   /* user + sys = load
@@ -103,7 +130,7 @@
     cpuload = 0;
   else
     cpuload = (256 * (load - oload)) / (total - ototal);
-
+  
   return cpuload;
 }
 
