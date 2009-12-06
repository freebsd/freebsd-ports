
$FreeBSD$

--- mono/mini/mini-ppc.h.orig
+++ mono/mini/mini-ppc.h
@@ -281,6 +281,14 @@
 	#define UCONTEXT_REG_FPRn(ctx, n) ((ctx)->uc_mcontext.__fpregs.__fpu_regs [(n)])
 	#define UCONTEXT_REG_NIP(ctx)     _UC_MACHINE_PC(ctx)
 	#define UCONTEXT_REG_LNK(ctx)     ((ctx)->uc_mcontext.__gregs [_REG_LR])
+#elif defined(__FreeBSD__)
+#include <ucontext.h>
+	typedef ucontext_t os_ucontext;
+
+	#define UCONTEXT_REG_Rn(ctx, n)   ((ctx)->uc_mcontext.mc_gpr [(n)])
+	#define UCONTEXT_REG_FPRn(ctx, n) ((ctx)->uc_mcontext.mc_fpreg [(n)])
+	#define UCONTEXT_REG_NIP(ctx)     ((ctx)->uc_mcontext.mc_srr0)
+	#define UCONTEXT_REG_LNK(ctx)     ((ctx)->uc_mcontext.mc_lr)
 #else
 #error Unknown OS
 #endif
