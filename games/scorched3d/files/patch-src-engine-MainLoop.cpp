--- ./src/engine/MainLoop.cpp.orig	Wed Sep  8 23:28:49 2004
+++ ./src/engine/MainLoop.cpp	Tue Jan 25 19:34:25 2005
@@ -23,7 +23,7 @@
 #include <common/Defines.h>
 #include <GLEXT/GLState.h>
 #include <GLEXT/GLInfo.h>
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 
 MainLoop::MainLoop() :  exitLoop_(false), lastDrawTime_(0.0f), flip_(false)
 {
