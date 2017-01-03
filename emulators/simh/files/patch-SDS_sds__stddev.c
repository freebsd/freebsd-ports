--- SDS/sds_stddev.c.orig	2016-12-01 22:43:43 UTC
+++ SDS/sds_stddev.c
@@ -395,7 +395,7 @@ t_stat r = SCPE_OK;
 
 if (ptp_ldr) {                                          /* need leader? */
     for (i = 0; i < 12; i++) {                          /* punch leader */
-        if (r = ptp_out (0))
+        if ((r = ptp_out (0)))
             break;
         }
     }
