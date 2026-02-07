--- Interdata/id_dp.c.orig	2016-12-01 22:43:42 UTC
+++ Interdata/id_dp.c
@@ -419,7 +419,7 @@ switch (dp_cmd & 0x7) {                 
         if (sch_actv (dp_dib.sch, dp_dib.dno)) {        /* sch transfer? */
             if (dp_dter (uptr, dp_1st))                 /* check xfr err */
                 return SCPE_OK;
-            if (r = dp_rds (uptr))                      /* read sec, err? */
+            if ((r = dp_rds (uptr)))                    /* read sec, err? */
                 return r;
             dp_1st = 0;
             t = sch_wrmem (dp_dib.sch, dpxb, DP_NUMBY); /* write to memory */
@@ -438,7 +438,7 @@ switch (dp_cmd & 0x7) {                 
                 return SCPE_OK;
             dp_bptr = sch_rdmem (dp_dib.sch, dpxb, DP_NUMBY); /* read from mem */
             dp_db = dpxb[dp_bptr - 1];                  /* last byte */
-            if (r = dp_wds (uptr))                      /* write sec, err? */
+            if ((r = dp_wds (uptr)))                    /* write sec, err? */
                 return r;
             dp_1st = 0;
             if (sch_actv (dp_dib.sch, dp_dib.dno)) {    /* more to do? */       
