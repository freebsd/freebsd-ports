--- Interdata/id_idc.c.orig	2016-12-01 22:43:42 UTC
+++ Interdata/id_idc.c
@@ -576,7 +576,7 @@ switch (uptr->FNC & CMC_MASK) {         
         if (sch_actv (idc_dib.sch, idc_dib.dno)) {      /* sch transfer? */
             if (idc_dter (uptr, idc_1st))               /* dte? done */
                 return SCPE_OK;
-            if (r = idc_rds (uptr))                     /* read sec, err? */
+            if ((r = idc_rds (uptr)))                   /* read sec, err? */
                 return r;
             idc_1st = 0;
             t = sch_wrmem (idc_dib.sch, idcxb, IDC_NUMBY); /* write mem */
@@ -595,7 +595,7 @@ switch (uptr->FNC & CMC_MASK) {         
                 return SCPE_OK;
             idc_bptr = sch_rdmem (idc_dib.sch, idcxb, IDC_NUMBY); /* read mem */
             idc_db = idcxb[idc_bptr - 1];               /* last byte */
-            if (r = idc_wds (uptr))                     /* write sec, err? */
+            if ((r = idc_wds (uptr)))                   /* write sec, err? */
                 return r;
             idc_1st = 0;
             if (sch_actv (idc_dib.sch, idc_dib.dno)) {  /* more to do? */       
