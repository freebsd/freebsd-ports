--- VAX/vax_cpu.c.orig	2016-12-01 22:43:43 UTC
+++ VAX/vax_cpu.c
@@ -642,7 +642,7 @@ for ( ;; ) {
 */
 
     if (trpirq) {                                       /* trap or interrupt? */
-        if (temp = GET_TRAP (trpirq)) {                 /* trap? */
+        if ((temp = GET_TRAP (trpirq))) {               /* trap? */
             cc = intexc (SCB_ARITH, cc, 0, IE_EXC);     /* take, clear trap */
             GET_CUR;                                    /* set cur mode */
             in_ie = 1;
@@ -650,7 +650,7 @@ for ( ;; ) {
             SP = SP - 4;
             in_ie = 0;
             }
-        else if (temp = GET_IRQL (trpirq)) {            /* interrupt? */
+        else if ((temp = GET_IRQL (trpirq))) {          /* interrupt? */
             int32 vec;
             if (temp == IPL_HLTPIN) {                   /* console halt? */
                 hlt_pin = 0;                            /* clear intr */
