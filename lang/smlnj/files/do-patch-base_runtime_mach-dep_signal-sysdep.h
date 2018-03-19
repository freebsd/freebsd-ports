--- base/runtime/mach-dep/signal-sysdep.h.orig	2018-03-16 11:21:38.240870000 -0700
+++ base/runtime/mach-dep/signal-sysdep.h	2018-03-16 11:22:06.398280000 -0700
@@ -447,8 +447,8 @@ extern void SetFSR();
 #  elif defined(OPSYS_FREEBSD)
     /** x86, FreeBSD **/
 #    define SIG_FAULT1		SIGFPE
-#    define INT_DIVZERO(s, c)	(((s) == SIGFPE) && ((c) == FPE_INTDIV_TRAP))
-#    define INT_OVFLW(s, c)	(((s) == SIGFPE) && ((c) == FPE_INTOVF_TRAP))
+#    define INT_DIVZERO(s, c)	(((s) == SIGFPE) && ((c) == FPE_INTDIV))
+#    define INT_OVFLW(s, c)	(((s) == SIGFPE) && ((c) == FPE_INTOVF))
 
 #    define SIG_GetCode(info, scp)	(info)
 #    define SIG_GetPC(scp)		((scp)->sc_pc)
