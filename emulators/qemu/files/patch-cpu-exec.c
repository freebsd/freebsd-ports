Index: qemu/cpu-exec.c
@@ -226,9 +226,9 @@
 
 int cpu_exec(CPUState *env1)
 {
-    target_ulong saved_T0, saved_T1;
+    unsigned long saved_T0, saved_T1;
 #if defined(reg_T2)
-    target_ulong saved_T2;
+    unsigned long saved_T2;
 #endif
     CPUState *saved_env;
 #if defined(TARGET_I386)
