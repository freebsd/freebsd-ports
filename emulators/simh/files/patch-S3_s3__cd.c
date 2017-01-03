--- S3/s3_cd.c.orig	2016-12-01 22:43:43 UTC
+++ S3/s3_cd.c
@@ -280,7 +280,7 @@ t_stat r;
 
 if (sim_is_active (&cdr_unit)) {                        /* busy? */
     sim_cancel (&cdr_unit);                             /* cancel */
-    if (r = cdr_svc (&cdr_unit)) return r;              /* process */
+    if ((r = cdr_svc (&cdr_unit))) return r;            /* process */
 }   
 
 if (((cdp_unit.flags & UNIT_ATT) != 0 ||
