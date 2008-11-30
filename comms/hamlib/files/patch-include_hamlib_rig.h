--- include/hamlib/rig.h.orig	2008-11-01 16:35:16.000000000 -0400
+++ include/hamlib/rig.h	2008-11-29 21:22:02.000000000 -0500
@@ -238,7 +238,7 @@
   RIG_STATUS_UNTESTED,		/*!< Written from available specs, rig unavailable for test, feedback wanted! */
   RIG_STATUS_BETA,		/*!< Beta quality */
   RIG_STATUS_STABLE,		/*!< Stable */
-  RIG_STATUS_BUGGY,		/*!< Was stable, but something broke it! */
+  RIG_STATUS_BUGGY		/*!< Was stable, but something broke it! */
 /*  RIG_STATUS_NEW	*	*!< Initial release of code 
  *  				!! Use of RIG_STATUS_NEW is deprecated. Do not use it anymore */
 };
