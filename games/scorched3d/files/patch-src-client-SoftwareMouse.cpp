--- ./src/client/SoftwareMouse.cpp.orig	Sat Aug  6 13:57:39 2005
+++ ./src/client/SoftwareMouse.cpp	Tue Aug  9 23:21:17 2005
@@ -25,7 +25,7 @@
 #include <GLEXT/GLState.h>
 #include <common/Defines.h>
 #include <common/OptionsDisplay.h>
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 
 SoftwareMouse *SoftwareMouse::instance_ = 0;
 
