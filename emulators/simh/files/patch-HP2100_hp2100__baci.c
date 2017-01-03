--- HP2100/hp2100_baci.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_baci.c
@@ -670,7 +670,7 @@ while (working_set) {
                     if ((baci_icw ^ baci_obuf) & OUT_BAUDRATE) {    /* baud rate change? */
                         baci_term.wait = service_time (baci_obuf);  /* set service time to match rate */
 
-                        if (baci_term.flags & UNIT_DIAG)        /* diagnostic mode? */
+                        if (baci_term.flags & UNIT_DIAG) {      /* diagnostic mode? */
                             if (baci_obuf & OUT_BAUDRATE) {     /* internal baud rate requested? */
                                 sim_activate (&baci_term,       /* activate I/O service */
                                               baci_term.wait);
@@ -687,6 +687,7 @@ while (working_set) {
                                     fprintf (sim_deb, ">>BACI cmds: [OTx%s] Terminal service stopped\n",
                                                       hold_or_clear);
                                 }
+                            }
                         }
 
                     baci_icw = baci_obuf;                   /* load new reference word */
@@ -1381,13 +1382,14 @@ else {                                  
 
 baci_fcount = baci_fcount + 1;                          /* increment occupancy counter */
 
-if (DEBUG_PRI (baci_dev, DEB_BUF))
+if (DEBUG_PRI (baci_dev, DEB_BUF)) {
     if (pass_thru)
         fprintf (sim_deb, ">>BACI buf:  Character %s put to UART transmitter holding register, "
                           "character counter = 1\n", fmt_char (ch));
     else
         fprintf (sim_deb, ">>BACI buf:  Character %s put to FIFO [%d], "
                           "character counter = %d\n", fmt_char (ch), index, baci_fcount);
+}
 
 if ((IO_MODE == RECV) && (baci_spchar [ch]))            /* receive mode and special character? */
     baci_status = baci_status | IN_SPCHAR;              /* set special char seen flag */
@@ -1447,12 +1449,13 @@ uint32 uart_bits, data_bits, data_mask, 
 if (baci_uart_clk > 0) {                                /* transfer in progress? */
     bit_low = (baci_icw & OUT_CD);                      /* get current receive bit */
 
-    if ((baci_uart_clk & 017) == 0)                     /* end of a bit? */
+    if ((baci_uart_clk & 017) == 0) {                   /* end of a bit? */
         if (IO_MODE == XMIT)                            /* transmit? */
             baci_uart_tr = baci_uart_tr >> 1;           /* shift new bit onto line */
         else                                            /* receive? */
             baci_uart_rr = (baci_uart_rr >> 1) &        /* shift new bit in */
                            (bit_low ? ~SIGN : -1);      /* (inverted sense) */
+    }
 
     if (bit_low) {                                      /* another low bit? */
         baci_bcount = baci_bcount + 1;                  /* update break counter */
