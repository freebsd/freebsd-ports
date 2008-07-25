--- CPU.xs.orig	2008-07-25 09:06:35.000000000 +0200
+++ CPU.xs	2008-07-25 09:24:13.000000000 +0200
@@ -35,6 +35,9 @@
  #define _have_cpu_clock
  #define _have_cpu_type
 #endif
+#ifdef __FreeBSD__
+ #include <sys/sysctl.h>
+#endif
 
 #ifdef WINDOWS
 /* Registry Functions */
@@ -237,6 +240,10 @@
 {
     int clock = 0;
     int retcode = 0;
+#ifdef __FreeBSD__
+    size_t len = sizeof(clock);
+    sysctlbyname("hw.clockrate", &clock, &len, NULL, 0);
+#else
 #ifdef __linux__
     int value = proc_cpuinfo_clock();
     if (value) clock = value;
@@ -263,12 +270,13 @@
         }
     }
 #endif
+#endif
     if (clock) {
 	    ST(0) = sv_newmortal();
 	    sv_setiv (ST(0), clock);
     } else {
 	    ST(0) = &PL_sv_undef;
-    }   
+    }
 }
 
 SV *
@@ -277,6 +285,10 @@
 {
     char *value = malloc(MAX_IDENT_SIZE);
     int retcode = 0;
+#ifdef __FreeBSD__
+   size_t len = MAX_IDENT_SIZE;
+   sysctlbyname("hw.model", value, &len, NULL, 0);
+#else
 #ifdef __linux__
     value = proc_cpuinfo_field ("model name");
     if (!value) value = proc_cpuinfo_field ("machine");
@@ -296,6 +308,7 @@
 	value = infop->pi_processor_type;
     }
 #endif
+#endif
     if (value) {
 	    ST(0) = sv_newmortal();
 	    sv_setpv (ST(0), value);
