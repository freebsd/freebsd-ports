--- ./src/client/SoftwareMouse.cpp.orig	Mon Apr  5 19:10:34 2004
+++ ./src/client/SoftwareMouse.cpp	Sun May 30 22:43:47 2004
@@ -25,7 +25,7 @@
 #include <GLEXT/GLState.h>
 #include <common/Defines.h>
 #include <common/OptionsDisplay.h>
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 
 SoftwareMouse *SoftwareMouse::instance_ = 0;
 
