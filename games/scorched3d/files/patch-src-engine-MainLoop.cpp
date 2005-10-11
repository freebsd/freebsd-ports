--- ./src/engine/MainLoop.cpp.orig	Sat Aug  6 13:57:39 2005
+++ ./src/engine/MainLoop.cpp	Tue Aug  9 23:21:20 2005
@@ -23,7 +23,7 @@
 #include <common/Defines.h>
 #include <GLEXT/GLState.h>
 #include <GLEXT/GLInfo.h>
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 
 MainLoop::MainLoop() :  exitLoop_(false), lastDrawTime_(0.0f), flip_(false)
 {
