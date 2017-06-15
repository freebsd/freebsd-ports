--- PDP11/pdp11_rk.c.orig	2016-12-01 22:43:42 UTC
+++ PDP11/pdp11_rk.c
@@ -545,13 +545,13 @@ if (wc && (err == 0)) {                 
                 rkxb[i] = 0;
             }
         if (rkcs & RKCS_INH) {                          /* incr inhibit? */
-            if (t = Map_WriteW (ma, 2, &rkxb[wc - 1])) { /* store last */
+            if ((t = Map_WriteW (ma, 2, &rkxb[wc - 1]))) { /* store last */
                 rker = rker | RKER_NXM;                 /* NXM? set flag */
                 wc = 0;                                 /* no transfer */
                 }
             }
         else {                                          /* normal store */
-            if (t = Map_WriteW (ma, wc << 1, rkxb)) {   /* store buf */
+            if ((t = Map_WriteW (ma, wc << 1, rkxb))) { /* store buf */
                 rker = rker | RKER_NXM;                 /* NXM? set flag */
                 wc = wc - t;                            /* adj wd cnt */
                 }
@@ -560,7 +560,7 @@ if (wc && (err == 0)) {                 
 
     case RKCS_WRITE:                                    /* write */
         if (rkcs & RKCS_INH) {                          /* incr inhibit? */
-            if (t = Map_ReadW (ma, 2, &comp)) {         /* get 1st word */
+            if ((t = Map_ReadW (ma, 2, &comp))) {       /* get 1st word */
                 rker = rker | RKER_NXM;                 /* NXM? set flag */
                 wc = 0;                                 /* no transfer */
                 }
@@ -568,7 +568,7 @@ if (wc && (err == 0)) {                 
                 rkxb[i] = comp;
             }
         else {                                          /* normal fetch */
-            if (t = Map_ReadW (ma, wc << 1, rkxb)) {    /* get buf */
+            if ((t = Map_ReadW (ma, wc << 1, rkxb))) {  /* get buf */
                 rker = rker | RKER_NXM;                 /* NXM? set flg */
                 wc = wc - t;                            /* adj wd cnt */
                 }
@@ -584,7 +584,7 @@ if (wc && (err == 0)) {                 
 
     case RKCS_WCHK:                                     /* write check */
         i = fxread (rkxb, sizeof (int16), wc, uptr->fileref);
-        if (err = ferror (uptr->fileref)) {             /* read error? */
+        if ((err = ferror (uptr->fileref))) {           /* read error? */
             wc = 0;                                     /* no transfer */
             break;
             }
