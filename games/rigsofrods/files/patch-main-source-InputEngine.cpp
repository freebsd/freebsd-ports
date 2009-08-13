--- main/source/InputEngine.cpp.orig	2009-06-20 11:17:44.000000000 +0400
+++ main/source/InputEngine.cpp	2009-08-13 00:37:23.000000000 +0400
@@ -1408,11 +1408,6 @@
 #define OIS_DYNAMIC_LIB
 #include <OIS.h>
 
-#if OGRE_PLATFORM == OGRE_PLATFORM_LINUX
-#include <X11/Xlib.h>
-#include <linux/LinuxMouse.h>
-#endif
-
 #ifndef NOOGRE
 #include "ogreconsole.h"
 #endif
@@ -1615,14 +1610,6 @@
 	static int lastmode = -1;
 	if(!mMouse)
 		return;
-#if OGRE_PLATFORM == OGRE_PLATFORM_LINUX
-	if((enable && lastmode == 0) || (!enable && lastmode == 1) || (lastmode == -1))
-	{
-		LogManager::getSingleton().logMessage("*** mouse grab: " + StringConverter::toString(enable));
-		((LinuxMouse *)mMouse)->grab(enable);
-		lastmode = enable?1:0;
-	}
-#endif
 }
 
 void InputEngine::hideMouse(bool visible)
@@ -1630,13 +1617,6 @@
 	static int mode = -1;
 	if(!mMouse)
 		return;
-#if OGRE_PLATFORM == OGRE_PLATFORM_LINUX
-	if((visible && mode == 0) || (!visible && mode == 1) || mode == -1)
-	{
-		((LinuxMouse *)mMouse)->hide(visible);
-		mode = visible?1:0;
-	}
-#endif
 }
 
 void InputEngine::setMousePosition(int x, int y, bool padding)
