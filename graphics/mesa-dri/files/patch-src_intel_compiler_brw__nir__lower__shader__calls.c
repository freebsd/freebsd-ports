--- src/intel/compiler/brw_nir_lower_shader_calls.c.orig	2021-06-30 18:18:55 UTC
+++ src/intel/compiler/brw_nir_lower_shader_calls.c
@@ -151,6 +151,12 @@ instr_is_shader_call(nir_instr *instr)
           intrin->intrinsic == nir_intrinsic_execute_callable;
 }
 
+#ifdef __FreeBSD__
+/* brw_nir_rt.h -> glthread.h -> u_thread.h -> pthread_np.h -> sys/cpuset.h -> sys/_bitset.h
+ * - defines `struct bitset` which clashes with the following
+ */
+#define bitset mesa_bitset
+#endif
 struct bitset {
    BITSET_WORD *set;
    unsigned size;
