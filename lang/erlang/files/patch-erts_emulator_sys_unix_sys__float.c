
$FreeBSD$

--- erts/emulator/sys/unix/sys_float.c.orig
+++ erts/emulator/sys/unix/sys_float.c
@@ -57,6 +57,7 @@
 void erts_thread_init_fp_exception(void)
 {
     unsigned long *fpe = erts_alloc(ERTS_ALC_T_FP_EXCEPTION, sizeof(*fpe));
+    *fpe = 0;
     erts_tsd_set(fpe_key, fpe);
 }
 
