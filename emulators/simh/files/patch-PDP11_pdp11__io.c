--- PDP11/pdp11_io.c.orig	2016-12-01 22:43:42 UTC
+++ PDP11/pdp11_io.c
@@ -373,17 +373,17 @@ init_ubus_tab ();                       
 init_mbus_tab ();                                       /* init Massbus tables */
 for (i = 0; i < 7; i++)                                 /* seed PIRQ intr */
     int_vec[i + 1][pirq_bit[i]] = VEC_PIRQ;
-if (r = cpu_build_dib ())                               /* build CPU entries */
+if ((r = cpu_build_dib ()))                               /* build CPU entries */
     return r;
 for (i = 0; (dptr = sim_devices[i]) != NULL; i++) {     /* loop thru dev */
     dibp = (DIB *) dptr->ctxt;                          /* get DIB */
     if (dibp && !(dptr->flags & DEV_DIS)) {             /* defined, enabled? */
         if (dptr->flags & DEV_MBUS) {                   /* Massbus? */
-            if (r = build_mbus_tab (dptr, dibp))        /* add to Mbus tab */
+            if ((r = build_mbus_tab (dptr, dibp)))      /* add to Mbus tab */
                 return r;
             }
         else {                                          /* no, Unibus */
-            if (r = build_ubus_tab (dptr, dibp))        /* add to Unibus tab */
+            if ((r = build_ubus_tab (dptr, dibp)))      /* add to Unibus tab */
                 return r;
             }
         }                                               /* end if enabled */
