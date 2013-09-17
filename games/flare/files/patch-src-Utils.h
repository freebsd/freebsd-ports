--- src/Utils.h.orig	2013-04-01 18:21:13.000000000 +0400
+++ src/Utils.h	2013-09-17 05:57:30.563226254 +0400
@@ -85,7 +85,7 @@
 };
 
 // Utility Functions
-int round(float f);
+int myround(float f);
 Point round(FPoint fp);
 Point screen_to_map(int x, int y, int camx, int camy);
 Point map_to_screen(int x, int y, int camx, int camy);
