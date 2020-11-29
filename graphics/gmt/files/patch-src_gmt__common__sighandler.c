--- src/gmt_common_sighandler.c.orig	2020-11-28 18:05:26 UTC
+++ src/gmt_common_sighandler.c
@@ -69,6 +69,8 @@ void backtrace_symbols_fd(void *const *buffer, int siz
 #  define UC_IP(uc) ((void *) (uc)->uc_mcontext.mc_rip)
 # elif defined( __arm__)
 #  define UC_IP(uc) ((void *) (uc)->uc_mcontext.arm_pc)
+# elif defined( __aarch64__)
+#  define UC_IP(uc) ((void *) (uc)->uc_mcontext.mc_gpregs.gp_elr)
 # elif defined(__ppc__)
 #  define UC_IP(uc) ((void *) (uc)->uc_mcontext.mc_srr0)
 # else
