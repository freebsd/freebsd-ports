--- runtime/flangrti/dumpregs.h.orig	2017-05-17 00:40:01 UTC
+++ runtime/flangrti/dumpregs.h
@@ -21,6 +21,6 @@
  *  Declare routines that access the machine registers
  */
 
-void dumpregs(gregset_t *regs);
-gregset_t *getRegs(ucontext_t *u);
+void dumpregs(void *regs);
+void *getRegs(ucontext_t *u);
 
