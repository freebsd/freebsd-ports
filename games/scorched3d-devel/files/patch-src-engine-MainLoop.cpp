--- ./src/engine/MainLoop.cpp.orig	Mon Feb 23 01:35:25 2004
+++ ./src/engine/MainLoop.cpp	Sun May 30 22:43:49 2004
@@ -22,7 +22,7 @@
 #include <common/OptionsDisplay.h>
 #include <common/Defines.h>
 #include <GLEXT/GLState.h>
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 
 MainLoop::MainLoop() :  exitLoop_(false), lastDrawTime_(0.0f), flip_(false)
 {
