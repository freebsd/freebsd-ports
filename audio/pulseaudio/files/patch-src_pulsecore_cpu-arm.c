--- src/pulsecore/cpu-arm.c.orig	2011-06-23 20:18:54.443125000 +0000
+++ src/pulsecore/cpu-arm.c	2013-03-09 23:00:50.000000000 +0000
@@ -82,10 +82,10 @@
 
 void pa_cpu_init_arm (void) {
 #if defined (__arm__)
+    pa_cpu_arm_flag_t flags = 0;
 #if defined (__linux__)
     char *cpuinfo, *line;
     int arch;
-    pa_cpu_arm_flag_t flags = 0;
 
     /* We need to read the CPU flags from /proc/cpuinfo because there is no user
      * space support to get the CPU features. This only works on linux AFAIK. */
