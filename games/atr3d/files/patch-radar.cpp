--- radar.cpp.orig	2008-02-19 19:31:03.000000000 +0100
+++ radar.cpp	2008-02-19 19:31:11.000000000 +0100
@@ -16,7 +16,7 @@
 {
   int i;
 
-  DrawText(ScreenWidth/2-12, ScreenHeight/3, "Radar", &Green);
+  DrawText(ScreenWidth/2-12, ScreenHeight/3, (char *)"Radar", &Green);
   DrawCircle(ScreenWidth/2, ScreenHeight/6, &Green, 64, 0.27, 0);
 
   for (i=0; i<MAX_PLAYERS; i++) {
