--- HP2100/hp2100_stddev.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_stddev.c
@@ -942,7 +942,7 @@ t_stat r;
 if (tty_mode & TM_PRI) {                                /* printing? */
     c = sim_tt_outcvt (c, TT_GET_MODE (tty_unit[TTO].flags));
     if (c >= 0) {                                       /* valid? */
-        if (r = sim_putchar_s (c)) return r;            /* output char */
+        if ((r = sim_putchar_s (c))) return r;          /* output char */
         tty_unit[TTO].pos = tty_unit[TTO].pos + 1;
         }
     }
@@ -1112,11 +1112,12 @@ while (working_set) {
             if (!sim_is_active (&clk_unit)) {                   /* clock running? */
                 clk_tick = clk_delay (0);                       /* get tick count */
 
-                if ((clk_unit.flags & UNIT_DIAG) == 0)          /* calibrated? */
+                if ((clk_unit.flags & UNIT_DIAG) == 0) {        /* calibrated? */
                     if (clk_select == 2)                        /* 10 msec. interval? */
                         clk_tick = sync_poll (INITIAL);         /* sync  poll */
                     else
                         sim_rtcn_init (clk_tick, TMR_CLK);      /* initialize timer */
+                    }
 
                 sim_activate (&clk_unit, clk_tick);             /* start clock */
                 clk_ctr = clk_delay (1);                        /* set repeat ctr */
