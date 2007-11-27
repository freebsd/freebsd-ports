--- rollout.h.orig	2007-11-25 23:05:53.000000000 +0100
+++ rollout.h	2007-11-25 23:06:00.000000000 +0100
@@ -59,8 +59,6 @@
 
 } rolloutstat;
 
-extern int nSkip;
-
 typedef void
 (rolloutprogressfunc) ( float arOutput[][ NUM_ROLLOUT_OUTPUTS ],
                         float arStdDev[][ NUM_ROLLOUT_OUTPUTS ],
