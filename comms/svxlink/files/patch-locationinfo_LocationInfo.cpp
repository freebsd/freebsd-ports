--- locationinfo/LocationInfo.cpp.orig	2014-04-09 23:26:23.000000000 -0700
+++ locationinfo/LocationInfo.cpp	2014-04-09 23:26:32.000000000 -0700
@@ -480,7 +480,7 @@
   }
 
   double tmp = sqrt(2.0 * loc_cfg.height * sqrt((loc_cfg.power / 10.0) *
-                        pow10(loc_cfg.gain / 10.0) / 2)) * range_factor;
+                        pow(10, loc_cfg.gain / 10.0) / 2)) * range_factor;
 
   return lrintf(tmp);
 
