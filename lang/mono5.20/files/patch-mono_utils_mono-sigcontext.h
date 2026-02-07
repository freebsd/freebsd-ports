--- mono/utils/mono-sigcontext.h.orig	2018-07-11 23:51:16 UTC
+++ mono/utils/mono-sigcontext.h
@@ -363,10 +363,10 @@
 #elif defined(__FreeBSD__)
 	typedef ucontext_t os_ucontext;
 
-	#define UCONTEXT_REG_Rn(ctx, n)   ((ctx)->uc_mcontext.mc_gpr [(n)])
-	#define UCONTEXT_REG_FPRn(ctx, n) ((ctx)->uc_mcontext.mc_fpreg [(n)])
-	#define UCONTEXT_REG_NIP(ctx)     ((ctx)->uc_mcontext.mc_srr0)
-	#define UCONTEXT_REG_LNK(ctx)     ((ctx)->uc_mcontext.mc_lr)
+	#define UCONTEXT_REG_Rn(ctx, n)   (((os_ucontext*)(ctx))->uc_mcontext.mc_gpr [(n)])
+	#define UCONTEXT_REG_FPRn(ctx, n) (((os_ucontext*)(ctx))->uc_mcontext.mc_fpreg [(n)])
+	#define UCONTEXT_REG_NIP(ctx)     (((os_ucontext*)(ctx))->uc_mcontext.mc_srr0)
+	#define UCONTEXT_REG_LNK(ctx)     (((os_ucontext*)(ctx))->uc_mcontext.mc_lr)
 #elif defined(_AIX)
 	typedef ucontext_t os_ucontext;
 
@@ -467,6 +467,13 @@
 	#define UCONTEXT_REG_SP(ctx) (((ucontext64_t*)(ctx))->uc_mcontext64->__ss.__sp)
 	#define UCONTEXT_REG_R0(ctx) (((ucontext64_t*)(ctx))->uc_mcontext64->__ss.__x [ARMREG_R0])
 	#define UCONTEXT_GREGS(ctx) (&(((ucontext64_t*)(ctx))->uc_mcontext64->__ss.__x))
+#elif defined(__FreeBSD__)
+#include <ucontext.h>
+	/* https://lists.freebsd.org/pipermail/freebsd-arm/2017-February/015611.html */
+	#define UCONTEXT_REG_PC(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_gpregs.gp_elr)
+	#define UCONTEXT_REG_SP(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_gpregs.gp_sp)
+	#define UCONTEXT_REG_R0(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_gpregs.gp_x [ARMREG_R0])
+	#define UCONTEXT_GREGS(ctx) (&(((ucontext_t*)(ctx))->uc_mcontext.mc_gpregs.gp_x))
 #else
 #include <ucontext.h>
 	#define UCONTEXT_REG_PC(ctx) (((ucontext_t*)(ctx))->uc_mcontext.pc)
