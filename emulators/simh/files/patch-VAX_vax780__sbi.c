--- VAX/vax780_sbi.c.orig	2016-12-01 22:43:43 UTC
+++ VAX/vax780_sbi.c
@@ -638,7 +638,7 @@ DIB *dibp;
 t_stat r;
 
 regptr = get_glyph (ptr, gbuf, 0);                      /* get glyph */
-if (slptr = strchr (gbuf, '/')) {                       /* found slash? */
+if ((slptr = strchr (gbuf, '/'))) {                     /* found slash? */
     regptr = strchr (ptr, '/');                         /* locate orig */
     *slptr = 0;                                         /* zero in string */
     }
@@ -784,15 +784,15 @@ for (i = 0; (dptr = sim_devices[i]) != N
     dibp = (DIB *) dptr->ctxt;                          /* get DIB */
     if (dibp && !(dptr->flags & DEV_DIS)) {             /* defined, enabled? */
         if (dptr->flags & DEV_NEXUS) {                  /* Nexus? */
-            if (r = build_nexus_tab (dptr, dibp))       /* add to dispatch table */
+            if ((r = build_nexus_tab (dptr, dibp)))     /* add to dispatch table */
                 return r;
             }
         else if (dptr->flags & DEV_MBUS) {              /* Massbus? */
-            if (r = build_mbus_tab (dptr, dibp))
+            if ((r = build_mbus_tab (dptr, dibp)))
                 return r;
             }
         else {                                          /* no, Unibus device */
-            if (r = build_ubus_tab (dptr, dibp))        /* add to dispatch tab */
+            if ((r = build_ubus_tab (dptr, dibp)))      /* add to dispatch tab */
                 return r;
             }                                           /* end else */
         }                                               /* end if enabled */
