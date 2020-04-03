--- src/c64_class.cpp.orig	2020-04-03 11:33:28 UTC
+++ src/c64_class.cpp
@@ -1757,7 +1757,7 @@ void C64Class::SetFullscreenAspectRatio(bool enable)
 void C64Class::AnalyzeSDLEvent(SDL_Event *event)
 {
     static bool joy_center_flag = true;
-    static char joy_axis_tbl[5] = {1,1,0,0,-1};
+    static signed char joy_axis_tbl[5] = {1,1,0,0,-1};
 
     SDL_Keymod keymod;
 
