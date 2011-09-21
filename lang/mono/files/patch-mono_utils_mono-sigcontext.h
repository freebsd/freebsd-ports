
$FreeBSD$

--- mono/utils/mono-sigcontext.h.orig
+++ mono/utils/mono-sigcontext.h
@@ -109,6 +109,10 @@
 	#define UCONTEXT_REG_RSI(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_rsi)
 	#define UCONTEXT_REG_RDI(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_rdi)
 	#define UCONTEXT_REG_RIP(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_rip)
+	#define UCONTEXT_REG_R8(ctx)  (((ucontext_t*)(ctx))->uc_mcontext.mc_r8)
+	#define UCONTEXT_REG_R9(ctx)  (((ucontext_t*)(ctx))->uc_mcontext.mc_r9)
+	#define UCONTEXT_REG_R10(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_r10)
+	#define UCONTEXT_REG_R11(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_r11)
 	#define UCONTEXT_REG_R12(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_r12)
 	#define UCONTEXT_REG_R13(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_r13)
 	#define UCONTEXT_REG_R14(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_r14)
