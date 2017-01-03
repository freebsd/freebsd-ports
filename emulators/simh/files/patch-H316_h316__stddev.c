--- H316/h316_stddev.c.orig	2016-12-01 22:43:42 UTC
+++ H316/h316_stddev.c
@@ -390,7 +390,7 @@ t_stat r;
 
 if (!(uptr->flags & UNIT_ATTABLE))
     return SCPE_NOFNC;
-if (r = attach_unit (uptr, cptr))
+if ((r = attach_unit (uptr, cptr)))
     return r;
 if (sim_switches & SWMASK ('A'))                        /* -a? ASCII */
     uptr->flags |= UNIT_ASC;
