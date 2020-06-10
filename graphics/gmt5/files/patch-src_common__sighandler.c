--- src/common_sighandler.c.orig	2019-02-25 06:44:38 UTC
+++ src/common_sighandler.c
@@ -69,6 +69,10 @@ void backtrace_symbols_fd(void *const *buffer, int siz
 #  define UC_IP(uc) ((void *) (uc)->uc_mcontext.mc_rip)
 # elif defined( __arm__)
 #  define UC_IP(uc) ((void *) (uc)->uc_mcontext.arm_pc)
+# elif defined( __ppc__)
+#  define UC_IP(uc) ((void *) (uc)->uc_mcontext.mc_srr0)
+# elif defined( __aarch64__)
+#  define UC_IP(uc) ((void *) (uc)->uc_mcontext.mc_gpregs.gp_elr)
 # else
 #  define UC_IP(uc) ((void *) (uc)->uc_mcontext.mc_eip)
 # endif
