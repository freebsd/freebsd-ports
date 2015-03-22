--- include/VBox/vmm/cpumctx.h.orig	2015-03-12 18:53:45.762704000 -0400
+++ include/VBox/vmm/cpumctx.h	2015-03-12 18:56:23.765105000 -0400
@@ -84,7 +84,7 @@
 # define CPUMSELREG_ARE_HIDDEN_PARTS_VALID(a_pVCpu, a_pSelReg) \
     (   ((a_pSelReg)->fFlags & CPUMSELREG_FLAGS_VALID) \
      && (   (a_pSelReg)->ValidSel == (a_pSelReg)->Sel \
-         || (   (a_pVCpu) /*!= NULL*/ \
+         || (   ((a_pVCpu) != NULL) \
              && (a_pSelReg)->ValidSel == ((a_pSelReg)->Sel & X86_SEL_MASK_OFF_RPL) \
              && ((a_pSelReg)->Sel      & X86_SEL_RPL) == 1 \
              && ((a_pSelReg)->ValidSel & X86_SEL_RPL) == 0 \
