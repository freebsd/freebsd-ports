--- src/ptrace/_UPT_access_fpreg.c.orig	2018-06-15 23:58:03 UTC
+++ src/ptrace/_UPT_access_fpreg.c
@@ -85,6 +85,8 @@ _UPT_access_fpreg (unw_addr_space_t as, unw_regnum_t r
           memcpy(&fpreg.fpr_xacc[reg], val, sizeof(unw_fpreg_t));
 #elif defined(__i386__)
           memcpy(&fpreg.fpr_acc[reg], val, sizeof(unw_fpreg_t));
+#elif defined(__aarch64__)
+          memcpy(&fpreg.fp_q[reg], val, sizeof(unw_fpreg_t));
 #else
 #error Fix me
 #endif
@@ -95,6 +97,8 @@ _UPT_access_fpreg (unw_addr_space_t as, unw_regnum_t r
           memcpy(val, &fpreg.fpr_xacc[reg], sizeof(unw_fpreg_t));
 #elif defined(__i386__)
           memcpy(val, &fpreg.fpr_acc[reg], sizeof(unw_fpreg_t));
+#elif defined(__aarch64__)
+          memcpy(val, &fpreg.fp_q[reg], sizeof(unw_fpreg_t));
 #else
 #error Fix me
 #endif
