--- VAX/vax_octa.c.orig	2016-12-01 22:43:43 UTC
+++ VAX/vax_octa.c
@@ -187,7 +187,7 @@ switch (opc) {
         break;
 
     case MOVH:
-        if (r = op_tsth (opnd[0])) {                    /* test for 0 */
+        if ((r = op_tsth (opnd[0]))) {                  /* test for 0 */
             h_write_o (spec, va, opnd, acc);            /* nz, write result */
             CC_IIZP_FP (r);                             /* set cc's */
             }
@@ -198,7 +198,7 @@ switch (opc) {
         break;
 
     case MNEGH:
-        if (r = op_tsth (opnd[0])) {                    /* test for 0 */
+        if ((r = op_tsth (opnd[0]))) {                  /* test for 0 */
             opnd[0] = opnd[0] ^ FPSIGN;                 /* nz, invert sign */
             h_write_o (spec, va, opnd, acc);            /* write result */
             CC_IIZZ_FP (opnd[0]);                       /* set cc's */
