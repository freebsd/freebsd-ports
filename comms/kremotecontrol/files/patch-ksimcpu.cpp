--- ksim/monitors/cpu/ksimcpu.cpp.orig	Fri Mar  7 23:10:34 2003
+++ ksim/monitors/cpu/ksimcpu.cpp	Sat Apr 26 02:41:45 2003
@@ -226,7 +226,7 @@
   static int oidCpuTime[CTL_MAXNAME + 2];
   static size_t oidCpuTimeLen = sizeof(oidCpuTime);
   long cpuTime[CPUSTATES];
-  unsigned int cpuTimeLen = sizeof(cpuTime);
+  size_t cpuTimeLen = sizeof(cpuTime);
   static char *name = "kern.cp_time";
   static int initialized = 0;
 
