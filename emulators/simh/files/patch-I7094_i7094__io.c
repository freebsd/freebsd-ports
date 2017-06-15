--- I7094/i7094_io.c.orig	2016-12-01 22:43:42 UTC
+++ I7094/i7094_io.c
@@ -795,7 +795,7 @@ switch (ch_sta[ch]) {                   
         if (ch_dev[ch].flags & DEV_7289) {              /* drum channel? */
             ir = ReadP (clc);                           /* read addr */
             ch_clc[ch] = CHAINC (clc);                  /* incr chan pc */
-            if (r = ch9_wr (ch, ir, 0))                 /* write to dev */
+            if ((r = ch9_wr (ch, ir, 0)))               /* write to dev */
                 return r;
             }
         else ch_clc[ch] = clc;                          /* set clc */
@@ -1003,7 +1003,7 @@ if (ch_dev[ch].flags & DEV_7909) {      
         return SCPE_OK;
 
     case CH9_SNS:                                       /* sense */
-        if (r = ch9_sel (ch, CHSL_SNS))                 /* send sense to dev */
+        if ((r = ch9_sel (ch, CHSL_SNS)))               /* send sense to dev */
             return r;
         ch_flags[ch] |= CHF_PRD;                        /* prepare to read */
         break;                                          /* next command */
@@ -1019,13 +1019,13 @@ if (ch_dev[ch].flags & DEV_7909) {      
             }
         ch_flags[ch] &= ~CHF_EOR;                       /* clear end */
         if (ch_op[ch] == CH9_CTLR) {                    /* CTLR? */
-            if (r = ch9_sel (ch, CHSL_RDS))             /* send read sel */
+            if ((r = ch9_sel (ch, CHSL_RDS)))           /* send read sel */
                 return r;
             ch_flags[ch] |= CHF_PRD;                    /* prep to read */
             ch_idf[ch] = 0;
             }
         else if (ch_op[ch] == CH9_CTLW) {               /* CTLW? */
-            if (r = ch9_sel (ch, CHSL_WRS))             /* end write sel */
+            if ((r = ch9_sel (ch, CHSL_WRS)))           /* end write sel */
                 return r;
             ch_flags[ch] |= CHF_PWR;                    /* prep to write */
             }
@@ -1035,7 +1035,7 @@ if (ch_dev[ch].flags & DEV_7909) {      
         if ((ch_wc[ch] == 0) || (ch_flags[ch] & CHF_EOR)) { /* wc == 0 or EOR? */
             if (ch_flags[ch] & (CHF_PRD|CHF_PWR|CHF_RDS|CHF_WRS)) {
                 ch_flags[ch] &= ~(CHF_PRD|CHF_PWR|CHF_RDS|CHF_WRS);
-                if (r = ch9_wr (ch, 0, CH9DF_STOP))     /* send stop */
+                if ((r = ch9_wr (ch, 0, CH9DF_STOP)))   /* send stop */
                     return r;
                 }
             if (ch_flags[ch] & CHF_EOR) {               /* EOR? */
@@ -1055,7 +1055,7 @@ if (ch_dev[ch].flags & DEV_7909) {      
             ch_flags[ch] &= ~CHF_EOR;                   /* ignore */
         else if (ch_flags[ch] & CHF_RDS)                /* read? */
             ch9_rd_putw (ch);
-        else if (r = ch9_wr_getw (ch))                  /* no, write */
+        else if ((r = ch9_wr_getw (ch)))                /* no, write */
             return r;
         if (ch_wc[ch] == 0)                             /* done? get next */
             break;
@@ -1164,7 +1164,7 @@ else {                                  
 
     case CH6_IOCD:                                      /* IOCD */
         if (ch_wc[ch]) {                                /* wc > 0? */
-            if (r = ch6_wr_getw (ch, TRUE))             /* send wd to dev; err? */
+            if ((r = ch6_wr_getw (ch, TRUE)))           /* send wd to dev; err? */
                 return r;
             if (ch_wc[ch])                              /* more to do? */
                 return SCPE_OK;
@@ -1174,7 +1174,7 @@ else {                                  
     case CH6_IOCP:                                      /* IOCP */
     case CH6_IOSP:                                      /* IOSP */
         if (ch_wc[ch]) {                                /* wc > 0? */
-            if (r = ch6_wr_getw (ch, FALSE))            /* send wd to dev; err? */
+            if ((r = ch6_wr_getw (ch, FALSE)))          /* send wd to dev; err? */
                 return r;
             if (ch_wc[ch])                              /* more to do? */
                 return SCPE_OK;
@@ -1184,7 +1184,7 @@ else {                                  
     case CH6_IOCT:                                      /* IOCT */
     case CH6_IOST:                                      /* IOST */
         if (ch_wc[ch]) {                                /* wc > 0? */
-            if (r = ch6_wr_getw (ch, FALSE))            /* send wd to dev; err? */
+            if ((r = ch6_wr_getw (ch, FALSE)))          /* send wd to dev; err? */
                 return r;
             if (ch_wc[ch])                              /* more to do? */
                 return SCPE_OK;
@@ -1193,7 +1193,7 @@ else {                                  
 
     case CH6_IORP:                                      /* IORP */
         if (!(ch_flags[ch] & CHF_EOR) && ch_wc[ch]) {   /* not EOR? (cdp, lpt) */
-            if (r = ch6_wr_getw (ch, TRUE))             /* send wd to dev; err? */
+            if ((r = ch6_wr_getw (ch, TRUE)))           /* send wd to dev; err? */
                 return r;
             if (ch_wc[ch])                              /* more to do? */
                 return SCPE_OK;
@@ -1203,7 +1203,7 @@ else {                                  
 
     case CH6_IORT:                                      /* IORT */
         if (!(ch_flags[ch] & CHF_EOR) && ch_wc[ch]) {   /* not EOR? (cdp, lpt) */
-            if (r = ch6_wr_getw (ch, TRUE))             /* send wd to dev; err? */
+            if ((r = ch6_wr_getw (ch, TRUE)))           /* send wd to dev; err? */
                 return r;
             if (ch_wc[ch])                              /* more to do? */
                 return SCPE_OK;
