--- I1401/i1401_cd.c.orig	2016-12-01 22:43:42 UTC
+++ I1401/i1401_cd.c
@@ -184,7 +184,7 @@ t_stat r;
 
 if (sim_is_active (&cdr_unit)) {                        /* busy? */
     sim_cancel (&cdr_unit);                             /* cancel */
-    if (r = cdr_svc (&cdr_unit))                        /* process */
+    if ((r = cdr_svc (&cdr_unit)))                      /* process */
         return r;
     }
 if ((cdr_unit.flags & UNIT_ATT) == 0)                   /* attached? */
