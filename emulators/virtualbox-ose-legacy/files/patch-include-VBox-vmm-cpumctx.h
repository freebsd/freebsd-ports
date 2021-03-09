--- include/VBox/vmm/cpumctx.h.orig	2020-05-13 19:36:46 UTC
+++ include/VBox/vmm/cpumctx.h
@@ -88,7 +88,7 @@ AssertCompileSize(CPUMSELREG, 24);
 # define CPUMSELREG_ARE_HIDDEN_PARTS_VALID(a_pVCpu, a_pSelReg) \
     (   ((a_pSelReg)->fFlags & CPUMSELREG_FLAGS_VALID) \
      && (   (a_pSelReg)->ValidSel == (a_pSelReg)->Sel \
-         || (   (a_pVCpu) /*!= NULL*/ \
+         || (   ((a_pVCpu) != NULL) \
              && (a_pSelReg)->ValidSel == ((a_pSelReg)->Sel & X86_SEL_MASK_OFF_RPL) \
              && ((a_pSelReg)->Sel      & X86_SEL_RPL) == 1 \
              && ((a_pSelReg)->ValidSel & X86_SEL_RPL) == 0 \
