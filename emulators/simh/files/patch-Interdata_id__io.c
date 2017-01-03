--- Interdata/id_io.c.orig	2016-12-01 22:43:42 UTC
+++ Interdata/id_io.c
@@ -358,7 +358,7 @@ if ((r != SCPE_OK) || (newmax == sch_max
 if (newmax == 0)                                        /* must be > 0 */
     return SCPE_ARG;
 if (newmax < sch_max) {                                 /* reducing? */
-    for (i = 0; dptr = sim_devices[i]; i++) {           /* loop thru dev */
+    for (i = 0; (dptr = sim_devices[i]); i++) {         /* loop thru dev */
         dibp = (DIB *) dptr->ctxt;                      /* get DIB */
         if (dibp && (dibp->sch >= (int32) newmax)) {    /* dev using chan? */
             printf ("Device %02X uses channel %d\n",
@@ -439,7 +439,7 @@ int32 i, j, t;
 uint32 r;
 
 for (i = t = 0; i < INTSZ; i++) {                       /* loop thru array */
-    if (r = int_req[i] & int_enb[i]) {                  /* find nz int wd */
+    if ((r = int_req[i] & int_enb[i])) {                /* find nz int wd */
         for (j = 0; j < 32; t++, j++) {
             if (r & (1u << j)) {
                 int_req[i] = int_req[i] & ~(1u << j);   /* clr request */
@@ -630,7 +630,7 @@ for (i = 0; i < (DEVNO / 32); i++)
 
 /* Test each device for conflict; add to map; init tables */
 
-for (i = 0; dptr = sim_devices[i]; i++) {               /* loop thru devices */
+for (i = 0; (dptr = sim_devices[i]); i++) {             /* loop thru devices */
     dibp = (DIB *) dptr->ctxt;                          /* get DIB */
     if ((dibp == NULL) || (dptr->flags & DEV_DIS))      /* exist, enabled? */
         continue;
