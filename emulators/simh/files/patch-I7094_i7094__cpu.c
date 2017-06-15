--- I7094/i7094_cpu.c.orig	2016-12-01 22:43:42 UTC
+++ I7094/i7094_cpu.c
@@ -664,14 +664,14 @@ while (reason == SCPE_OK) {             
         }
 
     if (sim_interval <= 0) {                            /* intv cnt expired? */
-        if (reason = sim_process_event ())              /* process events */
+        if ((reason = sim_process_event ()))            /* process events */
             break;
         chtr_pend = chtr_eval (NULL);                   /* eval chan traps */
         }
 
     for (i = 0; ch_req && (i < NUM_CHAN); i++) {        /* loop thru channels */
         if (ch_req & REQ_CH (i)) {                      /* channel request? */
-            if (reason = ch_proc (i))
+            if ((reason = ch_proc (i)))
                 break;
             }
         chtr_pend = chtr_eval (NULL);
@@ -1973,13 +1973,13 @@ while (reason == SCPE_OK) {             
             t_stat r;
             for (i = 0; (i < HALT_IO_LIMIT) && !ch_qidle (); i++) {
                 sim_interval = 0;
-                if (r = sim_process_event ())           /* process events */
+                if ((r = sim_process_event ()))         /* process events */
                     return r;
                 chtr_pend = chtr_eval (NULL);           /* eval chan traps */
                 while (ch_req) {                        /* until no ch req */
                     for (j = 0; j < NUM_CHAN; j++) {    /* loop thru channels */
                         if (ch_req & REQ_CH (j)) {      /* channel request? */
-                            if (r = ch_proc (j))
+                            if ((r = ch_proc (j)))
                                 return r;
                             }
                         chtr_pend = chtr_eval (NULL);
@@ -2438,7 +2438,7 @@ if (pc & HIST_PC) {                     
         }
     fputc ('\n', st);                                   /* end line */
     }                                                   /* end if instruction */
-else if (ch = HIST_CH (pc)) {                           /* channel? */
+else if ((ch = HIST_CH (pc))) {                         /* channel? */
     fprintf (st, "CH%c ", 'A' + ch - 1);
     fprintf (st, "%05o  ", pc & AMASK);
     fputs ("                                              ", st);
