--- VAX/vax_io.c.orig	2016-12-01 22:43:43 UTC
+++ VAX/vax_io.c
@@ -792,7 +792,7 @@ init_ubus_tab ();                       
 for (i = 0; (dptr = sim_devices[i]) != NULL; i++) {     /* loop thru dev */
     dibp = (DIB *) dptr->ctxt;                          /* get DIB */
     if (dibp && !(dptr->flags & DEV_DIS)) {             /* defined, enabled? */
-        if (r = build_ubus_tab (dptr, dibp))            /* add to bus tab */
+        if ((r = build_ubus_tab (dptr, dibp)))          /* add to bus tab */
             return r;
         }                                               /* end if enabled */
     }                                                   /* end for */
