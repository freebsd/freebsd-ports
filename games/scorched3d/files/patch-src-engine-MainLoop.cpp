--- ./src/engine/MainLoop.cpp.orig	Fri Jan 23 17:59:09 2004
+++ ./src/engine/MainLoop.cpp	Fri Jan 23 18:02:17 2004
@@ -22,7 +22,7 @@
 #include <common/OptionsDisplay.h>
 #include <common/Defines.h>
 #include <GLEXT/GLState.h>
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 
 MainLoop::MainLoop() :  exitLoop_(false), lastDrawTime_(0.0f)
 {
