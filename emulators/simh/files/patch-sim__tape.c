--- sim_tape.c.orig	2016-12-01 22:43:43 UTC
+++ sim_tape.c
@@ -404,7 +404,7 @@ t_addr opos;
 t_stat st;
 
 opos = uptr->pos;                                       /* old position */
-if (st = sim_tape_rdlntf (uptr, &tbc))                  /* read rec lnt */
+if ((st = sim_tape_rdlntf (uptr, &tbc)))                /* read rec lnt */
     return st;
 *bc = rbc = MTR_L (tbc);                                /* strip error flag */
 if (rbc > max) {                                        /* rec out of range? */
@@ -453,7 +453,7 @@ uint32 f = MT_GET_FMT (uptr);
 t_mtrlnt i, rbc, tbc;
 t_stat st;
 
-if (st = sim_tape_rdlntr (uptr, &tbc))                  /* read rec lnt */
+if ((st = sim_tape_rdlntr (uptr, &tbc)))                /* read rec lnt */
     return st;
 *bc = rbc = MTR_L (tbc);                                /* strip error flag */
 if (rbc > max)                                          /* rec out of range? */
