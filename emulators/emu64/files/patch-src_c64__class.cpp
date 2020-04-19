--- src/c64_class.cpp.orig	2020-04-11 10:05:13 UTC
+++ src/c64_class.cpp
@@ -27,9 +27,9 @@ int SDLThreadWarp(void *userdat);
 #define C64Takt 985248  // 50,124542Hz (Original C64 PAL)
 
 #ifdef _WIN32
-    #define AudioPufferSize (882)    // 882 bei 44.100 Khz
+    #define AudioPufferSize (1024)    // 882 bei 44.100 Khz
 #else
-    #define AudioPufferSize (882)    // 882 bei 44.100 Khz
+    #define AudioPufferSize (1024)    // 882 bei 44.100 Khz
 #endif
 
 #define RecPollingWaitStart 20
@@ -1757,7 +1757,7 @@ void C64Class::SetFullscreenAspectRatio(bool enable)
 void C64Class::AnalyzeSDLEvent(SDL_Event *event)
 {
     static bool joy_center_flag = true;
-    static char joy_axis_tbl[5] = {1,1,0,0,-1};
+    static signed char joy_axis_tbl[5] = {1,1,0,0,-1};
 
     SDL_Keymod keymod;
 
