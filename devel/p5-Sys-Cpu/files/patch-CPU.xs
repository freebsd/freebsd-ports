--- CPU.xs.orig	2010-09-03 23:30:18.000000000 +0100
+++ CPU.xs	2010-09-03 23:57:31.000000000 +0100
@@ -40,6 +40,11 @@
  #define _have_cpu_clock
  #define _have_cpu_type
 #endif
+#ifdef __FreeBSD__
+ #include <sys/sysctl.h>
+ #define _have_cpu_type
+ #define _have_cpu_clock
+#endif
 #ifdef WINDOWS
 /* Registry Functions */
 
@@ -317,6 +322,10 @@
     int value = proc_cpuinfo_clock();
     if (value) clock = value;
 #endif
+#ifdef __FreeBSD__
+    size_t len = sizeof(clock);
+    sysctlbyname("hw.clockrate", &clock, &len, NULL, 0);
+#endif
 #ifdef WINDOWS
     char *clock_str = malloc(MAX_IDENT_SIZE); 
     /*!! untested !!*/
@@ -356,6 +365,10 @@
 {
     char *value = malloc(MAX_IDENT_SIZE);
     int retcode = 0;
+#ifdef __FreeBSD__
+    size_t len = MAX_IDENT_SIZE;
+    sysctlbyname("hw.model", value, &len, NULL, 0);
+#endif
 #ifdef __linux__
     value = proc_cpuinfo_field ("model name");
     if (!value) value = proc_cpuinfo_field ("machine");
