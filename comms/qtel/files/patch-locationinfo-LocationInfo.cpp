--- ../svxlink-11.05.orig/locationinfo/LocationInfo.cpp	2011-03-01 16:11:17.000000000 -0800
+++ locationinfo/LocationInfo.cpp	2012-05-28 10:27:56.000000000 -0700
@@ -412,7 +412,7 @@
   }
 
   double tmp = sqrt(2.0 * loc_cfg.height * sqrt((loc_cfg.power / 10.0) *
-                        pow10(loc_cfg.gain / 10.0) / 2)) * range_factor;
+                        pow(10, loc_cfg.gain / 10.0) / 2)) * range_factor;
 
   return lrintf(tmp);
 
