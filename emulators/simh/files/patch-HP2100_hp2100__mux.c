--- HP2100/hp2100_mux.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_mux.c
@@ -650,11 +650,12 @@ while (working_set) {
         case ioIOO:                                     /* I/O data output */
             muxl_obuf = IODATA (stat_data);             /* store data */
 
-            if (DEBUG_PRI (muxu_dev, DEB_CPU))
+            if (DEBUG_PRI (muxu_dev, DEB_CPU)) {
                 if (muxl_obuf & OTL_P)
                     fprintf (sim_deb, ">>MUXl cpu:  [OTx%s] Parameter = %06o\n", hold_or_clear, muxl_obuf);
                 else
                     fprintf (sim_deb, ">>MUXl cpu:  [OTx%s] Data = %06o\n", hold_or_clear, muxl_obuf);
+                }
             break;
 
 
@@ -1107,11 +1108,12 @@ if (c & SCPE_BREAK) {                   
         mux_rbuf[ln] = 0;                               /* break returns NUL */
         mux_sta[ln] = mux_sta[ln] | LIU_BRK;            /* set break status */
 
-        if (DEBUG_PRI (muxu_dev, DEB_XFER))
+        if (DEBUG_PRI (muxu_dev, DEB_XFER)) {
             if (diag)
                 fputs (">>MUXl xfer: Break detected\n", sim_deb);
             else
                 fputs (">>MUXl xfer: Deferred break processed\n", sim_deb);
+            }
         }
 
     else {
