--- src/aarch64/Ginit.c.orig	2018-06-15 23:58:20 UTC
+++ src/aarch64/Ginit.c
@@ -44,7 +44,7 @@ static inline void *
 uc_addr (ucontext_t *uc, int reg)
 {
   if (reg >= UNW_AARCH64_X0 && reg <= UNW_AARCH64_V31)
-    return &uc->uc_mcontext.regs[reg];
+    return &uc->uc_mcontext.mc_gpregs.gp_x[reg];
   else
     return NULL;
 }
