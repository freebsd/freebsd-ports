--- lisp-kernel/platform-freebsdx8632.h.orig   2018-03-20 12:24:58.894882000 -0700
+++ lisp-kernel/platform-freebsdx8632.h        2018-03-20 12:26:51.327100000 -0700
@@ -42,6 +42,7 @@ typedef struct __ucontext ExceptionInfor
 
 #include <sys/types.h>
 #include <machine/npx.h>
+#include <machine/trap.h>
 #define xpGPRvector(x) ((natural *)(&((x)->uc_mcontext)))
 #define xpGPR(x,gprno) (xpGPRvector(x)[gprno])
 #define set_xpGPR(x,gpr,new) xpGPR((x),(gpr)) = (natural)(new)
@@ -56,7 +57,7 @@ extern void freebsd_sigreturn(ExceptionI
 #define IS_PAGE_FAULT(info,xp) (xp->uc_mcontext.mc_trapno == T_PAGEFLT)
 #define SIGRETURN(context) freebsd_sigreturn(context)
 
-#define AVX_CONTEXT_PRESENT(xp) ((xp)->uc_mcontext.mc_trapno & 4)
+#define AVX_CONTEXT_PRESENT(xp) ((xp)->uc_mcontext.mc_flags & 4)
 #define AVX_CONTEXT_PTR(xp) (((xp)->uc_mcontext.mc_fpstate[130]))
 #define AVX_CONTEXT_SIZE(xp) ((natural)((xp)->uc_mcontext.mc_fpstate[131]))
 
