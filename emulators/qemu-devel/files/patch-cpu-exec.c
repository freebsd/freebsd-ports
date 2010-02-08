--- a/cpu-exec.c
+++ b/cpu-exec.c
@@ -933,6 +933,20 @@
 # define TRAP_sig(context)			REG_sig(trap, context)
 #endif /* linux */
 
+#ifdef __FreeBSD__
+#include <ucontext.h>
+# define IAR_sig(context)		((context)->uc_mcontext.mc_srr0)
+# define MSR_sig(context)		((context)->uc_mcontext.mc_srr1)
+# define CTR_sig(context)		((context)->uc_mcontext.mc_ctr)
+# define XER_sig(context)		((context)->uc_mcontext.mc_xer)
+# define LR_sig(context)		((context)->uc_mcontext.mc_lr)
+# define CR_sig(context)		((context)->uc_mcontext.mc_cr)
+/* Exception Registers access */
+# define DAR_sig(context)		((context)->uc_mcontext.mc_dar)
+# define DSISR_sig(context)		((context)->uc_mcontext.mc_dsisr)
+# define TRAP_sig(context)		((context)->uc_mcontext.mc_exc)
+#endif /* __FreeBSD__ */
+
 #ifdef __APPLE__
 # include <sys/ucontext.h>
 typedef struct ucontext SIGCONTEXT;
@@ -962,7 +976,11 @@
                        void *puc)
 {
     siginfo_t *info = pinfo;
+#if defined (__FreeBSD__)
+    ucontext_t *uc = puc;
+#else
     struct ucontext *uc = puc;
+#endif
     unsigned long pc;
     int is_write;
 
