--- SDS/sds_dsk.c.orig	2016-12-01 22:43:43 UTC
+++ SDS/sds_dsk.c
@@ -204,7 +204,7 @@ switch (fnc) {                          
     case IO_READ:
         xfr_req = xfr_req & ~XFR_DSK;                   /* clr xfr req */
         if (dsk_bptr >= dsk_blnt) {                     /* no more data? */
-            if (r = dsk_read_buf (inst))                /* read sector */
+            if ((r = dsk_read_buf (inst)))              /* read sector */
                 return r;
             }
         dsk_wptr = dsk_bptr >> 2;                       /* word pointer */
@@ -219,7 +219,7 @@ switch (fnc) {                          
     case IO_WRITE:
         xfr_req = xfr_req & ~XFR_DSK;                   /* clr xfr req */
         if (dsk_bptr >= (DSK_NUMWD * 4)) {              /* full? */
-            if (r = dsk_write_buf (inst))               /* write sector */
+            if ((r = dsk_write_buf (inst)))             /* write sector */
                 return r;
             }
         dsk_wptr = dsk_bptr >> 2;                       /* word pointer */
