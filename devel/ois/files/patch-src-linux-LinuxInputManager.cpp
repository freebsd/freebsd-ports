--- src/linux/LinuxInputManager.cpp.orig	2008-01-28 00:24:28.000000000 +0300
+++ src/linux/LinuxInputManager.cpp	2008-06-16 11:12:52.000000000 +0400
@@ -22,7 +22,6 @@
 */
 #include "linux/LinuxInputManager.h"
 #include "linux/LinuxKeyboard.h"
-#include "linux/LinuxJoyStickEvents.h"
 #include "linux/LinuxMouse.h"
 #include "OISException.h"
 #include <cstdlib>
@@ -49,8 +48,6 @@
 //--------------------------------------------------------------------------------//
 LinuxInputManager::~LinuxInputManager()
 {
-	//Close all joysticks
-	LinuxJoyStick::_clearJoys(unusedJoyStickList);
 }
 
 //--------------------------------------------------------------------------------//
@@ -99,8 +96,6 @@
 void LinuxInputManager::_enumerateDevices()
 {
 	//Enumerate all attached devices
-	unusedJoyStickList = LinuxJoyStick::_scanJoys();
-	joySticks = unusedJoyStickList.size();
 }
 
 //----------------------------------------------------------------------------//
@@ -114,9 +109,6 @@
 	if( mouseUsed == false )
 		ret.insert(std::make_pair(OISMouse, mInputSystemName));
 
-	for(JoyStickInfoList::iterator i = unusedJoyStickList.begin(); i != unusedJoyStickList.end(); ++i)
-		ret.insert(std::make_pair(OISJoyStick, i->vendor));
-
 	return ret;
 }
 
@@ -127,7 +119,7 @@
 	{
 	case OISKeyboard: return 1;
 	case OISMouse: return 1;
-	case OISJoyStick: return joySticks;
+	case OISJoyStick: return 0;
 	default: return 0;
 	}
 }
@@ -139,7 +131,7 @@
 	{
 	case OISKeyboard: return keyboardUsed ? 0 : 1;
 	case OISMouse: return mouseUsed ? 0 : 1;
-	case OISJoyStick: return (int)unusedJoyStickList.size();
+	case OISJoyStick: return 0;
 	default: return 0;
 	}
 }
@@ -180,19 +172,6 @@
 			obj = new LinuxMouse(this, bufferMode, grabMouse, hideMouse);
 		break;
 	}
-	case OISJoyStick:
-	{
-		for(JoyStickInfoList::iterator i = unusedJoyStickList.begin(); i != unusedJoyStickList.end(); ++i)
-		{
-			if(vendor == "" || i->vendor == vendor)
-			{
-				obj = new LinuxJoyStick(this, bufferMode, *i);
-				unusedJoyStickList.erase(i);
-				break;
-			}
-		}
-		break;
-	}
 	default:
 		break;
 	}
@@ -208,11 +187,6 @@
 {
 	if( obj )
 	{
-		if( obj->type() == OISJoyStick )
-		{
-			unusedJoyStickList.push_back( ((LinuxJoyStick*)obj)->_getJoyInfo() );
-		}
-
 		delete obj;
 	}
 }
