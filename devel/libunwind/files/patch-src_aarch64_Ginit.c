--- src/aarch64/Ginit.c.orig	2020-03-31 15:35:32 UTC
+++ src/aarch64/Ginit.c
@@ -44,7 +44,7 @@ static inline void *
 uc_addr (unw_tdep_context_t *uc, int reg)
 {
   if (reg >= UNW_AARCH64_X0 && reg < UNW_AARCH64_V0)
-    return &uc->uc_mcontext.regs[reg];
+    return &uc->uc_mcontext.mc_gpregs.gp_x[reg];
   else if (reg >= UNW_AARCH64_V0 && reg <= UNW_AARCH64_V31)
     return &GET_FPCTX(uc)->vregs[reg - UNW_AARCH64_V0];
   else
