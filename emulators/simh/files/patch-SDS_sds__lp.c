--- SDS/sds_lp.c.orig	2016-12-01 22:43:43 UTC
+++ SDS/sds_lp.c
@@ -177,7 +177,7 @@ switch (fnc) {                          
         t = I_GETSKCND (inst);                          /* sks cond */
         if (((t == 020) && (!CHP (7, lpt_cct[lpt_ccp]))) || /* 14062: !ch 7 */
             ((t == 010) && (lpt_unit.flags & UNIT_ATT)) ||  /* 12062: !online */
-            (t == 004) && !lpt_err)                     /* 11062: !err */
+            ((t == 004) && !lpt_err))                   /* 11062: !err */
             *dat = 1;
         break;
 
