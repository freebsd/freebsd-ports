--- VAX/vax_cis.c.orig	2016-12-01 22:43:43 UTC
+++ VAX/vax_cis.c
@@ -331,7 +331,7 @@ switch (opc) {                          
             R[3] = (R[3] + 1) & LMASK;                  /* next string char */
             if (i >= sim_interval) {                    /* done with interval? */
                 sim_interval = 0;
-                if (r = sim_process_event ()) {         /* presumably WRU */
+                if ((r = sim_process_event ())) {       /* presumably WRU */
                     PC = fault_PC;                      /* backup up PC */
                     ABORT (r);                          /* abort flushes IB */
                     }
@@ -1550,7 +1550,7 @@ uint32 NibbleRshift (DSTR *dsrc, int32 s
 {
 int32 i, s, nc;
 
-if (s = sc * 4) {
+if ((s = sc * 4)) {
     for (i = DSTRMAX; i >= 0; i--) {
         nc = (dsrc->val[i] << (32 - s)) & LMASK;
         dsrc->val[i] = ((dsrc->val[i] >> s) |
@@ -1574,7 +1574,7 @@ uint32 NibbleLshift (DSTR *dsrc, int32 s
 {
 int32 i, s, nc;
 
-if (s = sc * 4) {
+if ((s = sc * 4)) {
     for (i = 0; i < DSTRLNT; i++) {
         nc = dsrc->val[i] >> (32 - s);
         dsrc->val[i] = ((dsrc->val[i] << s) |
