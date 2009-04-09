--- main/source/InputEngine.cpp.orig	2009-02-22 20:59:55.000000000 +0300
+++ main/source/InputEngine.cpp	2009-03-06 02:56:37.000000000 +0300
@@ -46,10 +46,10 @@
 #define OIS_DYNAMIC_LIB
 #include <OIS.h>
 
-#if OGRE_PLATFORM == OGRE_PLATFORM_LINUX
-#include <X11/Xlib.h>
-#include <linux/LinuxMouse.h>
-#endif
+//#if OGRE_PLATFORM == OGRE_PLATFORM_LINUX
+//#include <X11/Xlib.h>
+//#include <linux/LinuxMouse.h>
+//#endif
 
 using namespace std;
 using namespace Ogre;
@@ -204,7 +204,7 @@
 	if((enable && lastmode == 0) || (!enable && lastmode == 1) || (lastmode == -1))
 	{
 		LogManager::getSingleton().logMessage("*** mouse grab: " + StringConverter::toString(enable));
-		((LinuxMouse *)mMouse)->grab(enable);
+		//((LinuxMouse *)mMouse)->grab(enable);
 		lastmode = enable?1:0;
 	}
 #endif
@@ -218,7 +218,7 @@
 #if OGRE_PLATFORM == OGRE_PLATFORM_LINUX
 	if((visible && mode == 0) || (!visible && mode == 1) || mode == -1)
 	{
-		((LinuxMouse *)mMouse)->hide(visible);
+		//((LinuxMouse *)mMouse)->hide(visible);
 		mode = visible?1:0;
 	}
 #endif
