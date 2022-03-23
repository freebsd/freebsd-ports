--- src/aarch64/Ginit.c.orig	2021-11-30 17:12:31 UTC
+++ src/aarch64/Ginit.c
@@ -47,9 +47,17 @@ static inline void *
 uc_addr (unw_tdep_context_t *uc, int reg)
 {
   if (reg >= UNW_AARCH64_X0 && reg < UNW_AARCH64_V0)
+#if defined(__FreeBSD__)
+    return &uc->uc_mcontext.mc_gpregs.gp_x[reg];
+#else
     return &uc->uc_mcontext.regs[reg];
+#endif
   else if (reg >= UNW_AARCH64_V0 && reg <= UNW_AARCH64_V31)
+#if defined(__FreeBSD__)
+    return &GET_FPCTX(uc)->uc_mcontext.mc_fpregs.fp_q[reg - UNW_AARCH64_V0];
+#else
     return &GET_FPCTX(uc)->vregs[reg - UNW_AARCH64_V0];
+#endif
   else
     return NULL;
 }
