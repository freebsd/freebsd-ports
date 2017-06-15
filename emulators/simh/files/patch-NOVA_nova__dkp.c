--- NOVA/nova_dkp.c.orig	2016-12-01 22:43:42 UTC
+++ NOVA/nova_dkp.c
@@ -909,7 +909,7 @@ do  {
     if (uptr->FUNC == FCCY_READ) {                      /* read? */
             awc = fxread (tbuf, sizeof(uint16), DKP_NUMWD, uptr->fileref);
             for ( ; awc < DKP_NUMWD; awc++) tbuf[awc] = 0;
-            if (err = ferror (uptr->fileref))
+            if ((err = ferror (uptr->fileref)))
                 break;
             for (dx = 0; dx < DKP_NUMWD; dx++) {            /* loop thru buffer */
                 pa = MapAddr (dkp_map, (dkp_ma & AMASK));
@@ -925,7 +925,7 @@ do  {
                 dkp_ma = (dkp_ma + 1) & AMASK;
                 }
             fxwrite (tbuf, sizeof(int16), DKP_NUMWD, uptr->fileref);
-            if (err = ferror (uptr->fileref))
+            if ((err = ferror (uptr->fileref)))
                 break;
             }
 
