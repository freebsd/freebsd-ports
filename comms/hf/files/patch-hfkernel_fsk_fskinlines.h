--- hfkernel/fsk/fskinlines.h.orig	2011-08-05 10:56:43.000000000 -0400
+++ hfkernel/fsk/fskinlines.h	2011-08-05 11:00:59.000000000 -0400
@@ -84,7 +84,7 @@
 
 /* --------------------------------------------------------------------- */
 
-extern __inline__ unsigned int cc_replace(void)
+__inline__ unsigned int cc_replace(void)
 {
 	unsigned int j, k = CORRELATOR_CACHE;
 	int l = -1;
@@ -175,7 +175,7 @@
 
 /* --------------------------------------------------------------------- */
 
-extern __inline__ l1_soft_t do_filter(struct l1rxslots *slot, short *s)
+__inline__ l1_soft_t do_filter(struct l1rxslots *slot, short *s)
 {
 	unsigned int cc = slot->corr_cache;
 
@@ -319,7 +319,7 @@
 
 /* --------------------------------------------------------------------- */
 
-extern __inline__ l1_soft_t do_filter(struct l1rxslots *slot, short *s)
+ __inline__ l1_soft_t do_filter(struct l1rxslots *slot, short *s)
 {
 	
 	unsigned int cc = slot->corr_cache;
