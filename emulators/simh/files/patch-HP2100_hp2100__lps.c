--- HP2100/hp2100_lps.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_lps.c
@@ -372,11 +372,12 @@ while (working_set) {
             if (lps_unit.flags & UNIT_DIAG) {           /* diagnostic? */
                 lps_sta = lps_unit.buf;                 /* loop back data */
 
-                if (!(signal_set & ioCLC))                  /* CLC not asserted simultaneously? */
+                if (!(signal_set & ioCLC)) {               /* CLC not asserted simultaneously? */
                     if (UNIT_CPU_TYPE == UNIT_TYPE_211X)    /* 2114/15/16 CPU? */
                         sim_activate (&lps_unit, 3);        /* schedule flag after two instructions */
                     else                                    /* 2100 or 1000 */
                         sim_activate (&lps_unit, 2);        /* schedule flag after next instruction */
+                    }
                 }
 
             else {                                      /* real lpt, sched */
