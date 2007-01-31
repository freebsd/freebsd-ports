--- qemu/cpu-exec.c.orig	Wed Jan 31 16:58:03 2007
+++ qemu/cpu-exec.c	Wed Jan 31 17:08:11 2007
@@ -226,9 +226,9 @@
 
 int cpu_exec(CPUState *env1)
 {
-    int saved_T0, saved_T1;
+    long saved_T0, saved_T1;
 #if defined(reg_T2)
-    int saved_T2;
+    long saved_T2;
 #endif
     CPUState *saved_env;
 #if defined(TARGET_I386)
