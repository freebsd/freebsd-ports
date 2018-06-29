--- include/libunwind-aarch64.h.orig	2018-06-15 23:58:09 UTC
+++ include/libunwind-aarch64.h
@@ -177,7 +177,7 @@ typedef ucontext_t unw_tdep_context_t;
 
 #define unw_tdep_getcontext(uc) (({					\
   unw_tdep_context_t *unw_ctx = (uc);					\
-  register uint64_t *unw_base asm ("x0") = (uint64_t*) unw_ctx->uc_mcontext.regs;		\
+  register uint64_t *unw_base asm ("x0") = (uint64_t*) unw_ctx->uc_mcontext.mc_gpregs.gp_x;		\
   __asm__ __volatile__ (						\
      "stp x0, x1, [%[base], #0]\n" \
      "stp x2, x3, [%[base], #16]\n" \
