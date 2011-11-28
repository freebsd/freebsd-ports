--- zpaq.cpp.orig	2011-11-28 15:50:58.000000000 -0500
+++ zpaq.cpp	2011-11-28 16:01:21.000000000 -0500
@@ -70,6 +70,7 @@
 #define PTHREAD 1
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/sysctl.h>
 #include <unistd.h>
 #else
 #include <windows.h>
@@ -195,6 +196,11 @@
   int rc=0;  // result
 #ifdef unix
 
+  size_t rcsize;
+  rcsize = sizeof(rc);
+  if (sysctlbyname("kern.smp.cpus", &rc, &rcsize, NULL, 0) < 0) return 1;
+#elif 0
+
   // Count lines of the form "processor\t: %d\n" in /proc/cpuinfo
   // where %d is 0, 1, 2,..., rc-1
   FILE *in=fopen("/proc/cpuinfo", "r");
