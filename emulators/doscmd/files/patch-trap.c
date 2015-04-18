--- trap.c.orig	2011-08-26 16:48:21 UTC
+++ trap.c
@@ -295,7 +295,7 @@ sigbus(struct sigframe *sf)
     callback_t		func;
     regcontext_t	*REGS = (regcontext_t *)(&sf->sf_uc.uc_mcontext);
 
-    if (!(R_EFLAGS && PSL_VM))
+    if (!(R_EFLAGS & PSL_VM))
 	fatal("SIGBUS in the emulator\n");
 
     if ((int)sf->sf_siginfo != 0) {
