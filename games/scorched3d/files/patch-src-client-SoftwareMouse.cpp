--- ./src/client/SoftwareMouse.cpp.orig	Fri Sep 10 14:45:45 2004
+++ ./src/client/SoftwareMouse.cpp	Tue Jan 25 19:34:21 2005
@@ -25,7 +25,7 @@
 #include <GLEXT/GLState.h>
 #include <common/Defines.h>
 #include <common/OptionsDisplay.h>
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 
 SoftwareMouse *SoftwareMouse::instance_ = 0;
 
