--- mono/utils/mono-sigcontext.h.orig	2018-08-24 15:17:13 UTC
+++ mono/utils/mono-sigcontext.h
@@ -363,10 +363,10 @@ typedef struct ucontext {
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
 #endif
 
 #elif defined(TARGET_ARM)
