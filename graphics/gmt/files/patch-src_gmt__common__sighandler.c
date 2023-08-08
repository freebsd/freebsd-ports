--- src/gmt_common_sighandler.c.orig	2023-07-28 19:57:48 UTC
+++ src/gmt_common_sighandler.c
@@ -84,7 +84,7 @@ void backtrace_symbols_fd(void *const *buffer, int siz
 # ifdef __x86_64__
 #  define UC_IP(uc) ((void *) (uc)->uc_mcontext.mc_rip)
 # elif defined( __arm__)
-#  define UC_IP(uc) ((void *) (uc)->uc_mcontext.arm_pc)
+#  define UC_IP(uc) ((void *) (uc)->uc_mcontext.__gregs[_REG_PC])
 # elif defined( __aarch64__)
 #  define UC_IP(uc) ((void *) (uc)->uc_mcontext.mc_gpregs.gp_elr)
 # elif defined(__ppc__)
