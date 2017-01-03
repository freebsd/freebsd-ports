--- PDP11/pdp11_cpu.c.orig	2016-12-01 22:43:42 UTC
+++ PDP11/pdp11_cpu.c
@@ -732,7 +732,7 @@ while (reason == 0)  {
 
     if (trap_req) {                                     /* check traps, ints */
         trapea = 0;                                     /* assume srch fails */
-        if (t = trap_req & TRAP_ALL) {                  /* if a trap */
+        if ((t = trap_req & TRAP_ALL)) {                /* if a trap */
             for (trapnum = 0; trapnum < TRAP_V_MAX; trapnum++) {
                 if ((t >> trapnum) & 1) {               /* trap set? */
                     trapea = trap_vec[trapnum];         /* get vec, clr */
