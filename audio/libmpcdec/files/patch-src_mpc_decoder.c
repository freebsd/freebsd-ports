--- src/mpc_decoder.c.orig	Fri Jun  3 09:29:30 2005
+++ src/mpc_decoder.c	Fri Jun  3 09:29:49 2005
@@ -486,7 +486,7 @@
 
 #endif
 #else
-#define MPC_MULTIPLY_SCF(CcVal, SCF_idx) \
+#define MPC_MULTIPLY_SCF(CcVal, SCF_idx) \
     MPC_MULTIPLY(CcVal, d->SCF[SCF_idx])
 #endif
     // requantization and scaling of subband-samples
