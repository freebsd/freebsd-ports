--- include/libunwind-aarch64.h.orig	2018-12-20 18:10:32 UTC
+++ include/libunwind-aarch64.h
@@ -212,7 +212,7 @@ typedef struct
 
 #define unw_tdep_getcontext(uc) (({					\
   unw_tdep_context_t *unw_ctx = (uc);					\
-  register uint64_t *unw_base __asm__ ("x0") = (uint64_t*) unw_ctx->uc_mcontext.regs;		\
+  register uint64_t *unw_base __asm__ ("x0") = (uint64_t*) unw_ctx->uc_mcontext.mc_gpregs.gp_x;		\
   __asm__ __volatile__ (						\
      "stp x0, x1, [%[base], #0]\n" \
      "stp x2, x3, [%[base], #16]\n" \
