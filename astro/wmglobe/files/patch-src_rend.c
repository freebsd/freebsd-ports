--- src/rend.c.orig	2020-09-15 14:31:47 UTC
+++ src/rend.c
@@ -33,6 +33,20 @@
 
 #include "wmglobe.h"
 
+/*
+ * variables globales
+ */
+
+double solu[DIAMETRE][DIAMETRE][3];
+int tabsolu[DIAMETRE][DIAMETRE];
+double moon_lat,moon_long;
+struct timeval tlast, tnext, trend, tdelay, tini, tbase;
+time_t tsunpos;
+double center_dist;
+double light_x, light_y, light_z;	/* vector of sunlight with lengt 1 */
+double c_coef, b_coef;
+int radius_proj, aml;
+
 static RColor mygetMapColorLinear
     (double longitude, double latitude, double angle);
 
