--- PDP11/pdp11_hk.c.orig	2016-12-01 22:43:42 UTC
+++ PDP11/pdp11_hk.c
@@ -887,7 +887,7 @@ switch (fnc) {                          
         err = fseek (uptr->fileref, da * sizeof (int16), SEEK_SET);
         if (uptr->FNC == FNC_WRITE) {                   /* write? */
             if (hkcs2 & CS2_UAI) {                      /* no addr inc? */
-                if (t = Map_ReadW (ba, 2, &comp)) {     /* get 1st wd */
+                if ((t = Map_ReadW (ba, 2, &comp))) {   /* get 1st wd */
                     wc = 0;                             /* NXM, no xfr */
                     hkcs2 = hkcs2 | CS2_NEM;            /* set nxm err */
                     }
@@ -895,7 +895,7 @@ switch (fnc) {                          
                     hkxb[i] = comp;
                 }
             else {                                      /* normal */
-                if (t = Map_ReadW (ba, wc << 1, hkxb)) { /* get buf */
+                if ((t = Map_ReadW (ba, wc << 1, hkxb))) { /* get buf */
                     wc = wc - (t >> 1);                 /* NXM, adj wc */
                     hkcs2 = hkcs2 | CS2_NEM;            /* set nxm err */
                     }
@@ -915,13 +915,13 @@ switch (fnc) {                          
             for ( ; i < wc; i++)                        /* fill buf */
                 hkxb[i] = 0;
             if (hkcs2 & CS2_UAI) {                      /* no addr inc? */
-                if (t = Map_WriteW (ba, 2, &hkxb[wc - 1])) {
+                if ((t = Map_WriteW (ba, 2, &hkxb[wc - 1]))) {
                     wc = 0;                             /* NXM, no xfr */
                     hkcs2 = hkcs2 | CS2_NEM;            /* set nxm err */
                     }
                 }
             else {                                      /* normal */
-                if (t = Map_WriteW (ba, wc << 1, hkxb)) {       /* put buf */
+                if ((t = Map_WriteW (ba, wc << 1, hkxb))) {     /* put buf */
                     wc = wc - (t >> 1);                 /* NXM, adj wc */
                     hkcs2 = hkcs2 | CS2_NEM;            /* set nxm err */
                     }
