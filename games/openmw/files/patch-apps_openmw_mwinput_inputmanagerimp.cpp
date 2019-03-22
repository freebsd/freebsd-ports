--- apps/openmw/mwinput/inputmanagerimp.cpp.orig	2019-03-10 10:50:29 UTC
+++ apps/openmw/mwinput/inputmanagerimp.cpp
@@ -121,11 +121,12 @@ namespace MWInput
                 SDL_ControllerDeviceEvent evt;
                 evt.which = i;
                 controllerAdded(mFakeDeviceID, evt);
-                Log(Debug::Info) << "Detected game controller: " << SDL_GameControllerNameForIndex(i);
+                //Bug in FreeBSD's SDL? SDL_GameControllerNameForIndex returns NULL
+                Log(Debug::Info) << "Detected game controller: " << i;
             }
             else
             {
-                Log(Debug::Info) << "Detected unusable controller: " << SDL_JoystickNameForIndex(i);
+                Log(Debug::Info) << "Detected unusable controller: " << i;
             }
         }
 
