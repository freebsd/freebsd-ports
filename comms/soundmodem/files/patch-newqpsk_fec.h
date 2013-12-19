--- newqpsk/fec.h.orig	2002-08-09 15:01:52.000000000 -0500
+++ newqpsk/fec.h	2013-12-14 17:37:25.000000000 -0500
@@ -13,7 +13,7 @@
 
 /* --------------------------------------------------------------------- */
 
-extern inline void init_fec(struct fecstate *f)
+static inline void init_fec(struct fecstate *f)
 {
 	switch (f->feclevel) {
 	case 0:
@@ -33,7 +33,7 @@
 
 /* --------------------------------------------------------------------- */
 
-extern inline void init_inlv(struct fecstate *f)
+static inline void init_inlv(struct fecstate *f)
 {
         int i;
 
