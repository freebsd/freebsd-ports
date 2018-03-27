--- lisp-kernel/platform-freebsdx8664.h.orig   2018-03-20 12:25:05.151015000 -0700
+++ lisp-kernel/platform-freebsdx8664.h        2018-03-20 12:26:36.751044000 -0700
@@ -47,6 +47,7 @@ typedef struct __ucontext ExceptionInfor
 #define REG_RSP 23
 
 #include <machine/fpu.h>
+#include <machine/trap.h>
 #define xpGPRvector(x) ((natural *)(&((x)->uc_mcontext)))
 #define xpGPR(x,gprno) (xpGPRvector(x)[gprno])
 #define set_xpGPR(x,gpr,new) xpGPR((x),(gpr)) = (natural)(new)
@@ -67,7 +68,7 @@ extern void freebsd_sigreturn(ExceptionI
    fbsd 9.1 headers; if we built on an older OS version, we still need
    to know about this if we run on 9.1+ */
 
-#define AVX_CONTEXT_PRESENT(xp) ((xp)->uc_mcontext.mc_trapno & 4)
+#define AVX_CONTEXT_PRESENT(xp) ((xp)->uc_mcontext.mc_flags & 4)
 #define AVX_CONTEXT_PTR(xp) (((xp)->uc_mcontext.mc_fpstate[66]))
 #define AVX_CONTEXT_SIZE(xp) ((natural)((xp)->uc_mcontext.mc_fpstate[67]))
 
