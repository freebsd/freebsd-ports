--- HP2100/hp2100_ipl.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_ipl.c
@@ -623,7 +623,7 @@ uptr->filename = tptr;                  
 sim_activate (uptr, POLL_FIRST);                        /* activate first poll "immediately" */
 if (sim_switches & SWMASK ('W')) {                      /* wait? */
     for (i = 0; i < 30; i++) {                          /* check for 30 sec */
-        if (t = ipl_check_conn (uptr))                  /* established? */
+        if ((t = ipl_check_conn (uptr)))                /* established? */
             break;
         if ((i % 10) == 0)                              /* status every 10 sec */
             printf ("Waiting for connnection\n");
