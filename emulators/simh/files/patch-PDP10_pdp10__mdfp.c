--- PDP10/pdp10_mdfp.c.orig	2016-12-01 22:43:42 UTC
+++ PDP10/pdp10_mdfp.c
@@ -493,7 +493,7 @@ if (a.fhi >= 2 * b.fhi) {               
     SETF (F_AOV | F_DCK | F_FOV | F_T1);
     return FALSE;
     }
-if (savhi = a.fhi) {                                    /* dvd = 0? quo = 0 */
+if ((savhi = a.fhi)) {                                  /* dvd = 0? quo = 0 */
     a.sign = a.sign ^ b.sign;                           /* result sign */
     a.exp = a.exp - b.exp + FP_BIAS + 1;                /* result exponent */
     a.fhi = a.fhi / (b.fhi >> (FP_N_FHI + 1));          /* do divide */
