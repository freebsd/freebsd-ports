--- base/runtime/mach-dep/signal-sysdep.h.orig	2017-08-27 15:28:34.000000000 +0200
+++ base/runtime/mach-dep/signal-sysdep.h	2018-03-17 18:49:11.672602000 +0100
@@ -447,8 +447,8 @@
 #  elif defined(OPSYS_FREEBSD)
     /** x86, FreeBSD **/
 #    define SIG_FAULT1		SIGFPE
-#    define INT_DIVZERO(s, c)	(((s) == SIGFPE) && ((c) == FPE_INTDIV_TRAP))
-#    define INT_OVFLW(s, c)	(((s) == SIGFPE) && ((c) == FPE_INTOVF_TRAP))
+#    define INT_DIVZERO(s, c)	(((s) == SIGFPE) && ((c) == FPE_INTDIV))
+#    define INT_OVFLW(s, c)	(((s) == SIGFPE) && ((c) == FPE_INTOVF))
 
 #    define SIG_GetCode(info, scp)	(info)
 #    define SIG_GetPC(scp)		((scp)->sc_pc)
@@ -568,8 +568,8 @@
 #  elif defined(OPSYS_FREEBSD)
     /** amd64, FreeBSD **/
 #    define SIG_FAULT1		SIGFPE
-#    define INT_DIVZERO(s, c)	(((s) == SIGFPE) && ((c) == FPE_INTDIV_TRAP))
-#    define INT_OVFLW(s, c)	(((s) == SIGFPE) && ((c) == FPE_INTOVF_TRAP))
+#    define INT_DIVZERO(s, c)	(((s) == SIGFPE) && ((c) == FPE_INTDIV))
+#    define INT_OVFLW(s, c)	(((s) == SIGFPE) && ((c) == FPE_INTOVF))
 
 #    define SIG_GetCode(info, scp)	(info)
 #    define SIG_GetPC(scp)		((scp)->sc_pc)
