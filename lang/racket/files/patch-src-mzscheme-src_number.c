--- ../mzscheme/src/number.c.orig	2008-05-07 23:15:18.000000000 +0200
+++ ../mzscheme/src/number.c	2008-06-27 08:07:23.000000000 +0200
@@ -52,6 +52,11 @@
 # define MAX_SHIFT_EVER 32
 #endif
 
+#include <sys/param.h>
+#include <fenv.h>
+#pragma STDC FENV_ACCESS ON
+
+
 /* globals */
 double scheme_infinity_val, scheme_minus_infinity_val;
 
@@ -152,7 +157,11 @@
   MZ_SIGSET(SIGFPE, SIG_IGN);
 #endif
 #ifdef FREEBSD_CONTROL_387
+#if __FreeBSD_version < 800000
   __fpsetreg(FP_MSKS_FLD, FP_MSKS_REG, FP_MSKS_FLD, FP_MSKS_OFF);
+#else
+ fedisableexcept(FE_ALL_EXCEPT);
+#endif
 #endif
 #ifdef LINUX_CONTROL_387
   __setfpucw(_FPU_EXTENDED + _FPU_RC_NEAREST + 0x3F);
