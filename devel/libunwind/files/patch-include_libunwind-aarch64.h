--- include/libunwind-aarch64.h.orig	2021-12-01 00:46:39 UTC
+++ include/libunwind-aarch64.h
@@ -226,15 +226,24 @@ typedef struct
 #else
 /* On AArch64, we can directly use ucontext_t as the unwind context.  */
 typedef ucontext_t unw_tdep_context_t;
+#if defined(__FreeBSD__)
+typedef ucontext_t unw_fpsimd_context_t;
 #endif
+#endif
 
 
 #include "libunwind-common.h"
 #include "libunwind-dynamic.h"
 
+#if defined(__FreeBSD__)
+#define UNW_BASE register uint64_t unw_base __asm__ ("x0") = (uint64_t) unw_ctx->uc_mcontext.mc_gpregs.gp_x[0];
+#else
+#define UNW_BASE register uint64_t unw_base __asm__ ("x0") = (uint64_t) unw_ctx->uc_mcontext.regs;
+#endif
+
 #define unw_tdep_getcontext(uc) ({					\
   unw_tdep_context_t *unw_ctx = (uc);					\
-  register uint64_t unw_base __asm__ ("x0") = (uint64_t) unw_ctx->uc_mcontext.regs; \
+  UNW_BASE \
   __asm__ __volatile__ (					        \
      "stp x0, x1, [%[base], #0]\n" \
      "stp x2, x3, [%[base], #16]\n" \
