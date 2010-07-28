
$FreeBSD$

--- mono/utils/mono-sigcontext.h.orig
+++ mono/utils/mono-sigcontext.h
@@ -80,6 +80,19 @@
 
 #ifdef __FreeBSD__
 #define UCONTEXT_GREGS(ctx)	&(((ucontext_t*)(ctx))->uc_mcontext)
+	#define UCONTEXT_REG_RAX(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_rax)
+	#define UCONTEXT_REG_RBX(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_rbx)
+	#define UCONTEXT_REG_RCX(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_rcx)
+	#define UCONTEXT_REG_RDX(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_rdx)
+	#define UCONTEXT_REG_RBP(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_rbp)
+	#define UCONTEXT_REG_RSP(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_rsp)
+	#define UCONTEXT_REG_RSI(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_rsi)
+	#define UCONTEXT_REG_RDI(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_rdi)
+	#define UCONTEXT_REG_RIP(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_rip)
+	#define UCONTEXT_REG_R12(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_r12)
+	#define UCONTEXT_REG_R13(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_r13)
+	#define UCONTEXT_REG_R14(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_r14)
+	#define UCONTEXT_REG_R15(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_r15)
 #elif defined(__OpenBSD__)
 	/* OpenBSD/amd64 has no gregs array, ucontext_t == sigcontext */
 	#define UCONTEXT_REG_RAX(ctx) ((ctx)->sc_rax)
