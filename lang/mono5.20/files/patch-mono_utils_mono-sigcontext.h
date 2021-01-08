--- mono/utils/mono-sigcontext.h.orig	2018-07-11 23:51:16 UTC
+++ mono/utils/mono-sigcontext.h
@@ -460,6 +460,13 @@ typedef struct ucontext {
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
