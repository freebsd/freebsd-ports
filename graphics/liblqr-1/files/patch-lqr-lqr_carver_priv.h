--- lqr/lqr_carver_priv.h.orig	2008-11-01 04:42:18.000000000 +0300
+++ lqr/lqr_carver_priv.h	2009-03-25 22:02:08.000000000 +0300
@@ -204,7 +204,7 @@
 LqrRetVal lqr_carver_build_vsmap (LqrCarver * r, gint depth);    /* visibility */
 
 /* internal functions for maps computation */
-inline gfloat lqr_carver_read (LqrCarver * r, gint x, gint y); /* read the average value at given point */
+gfloat lqr_carver_read (LqrCarver * r, gint x, gint y); /* read the average value at given point */
 void lqr_carver_compute_e (LqrCarver * r, gint x, gint y);      /* compute energy of point at c (fast) */
 void lqr_carver_update_emap (LqrCarver * r);    /* update energy map after seam removal */
 void lqr_carver_update_mmap (LqrCarver * r);    /* minpath */
