--- apps/openmw/mwinput/inputmanagerimp.cpp.orig	2017-06-29 22:52:28 UTC
+++ apps/openmw/mwinput/inputmanagerimp.cpp
@@ -122,11 +122,12 @@ namespace MWInput
                 SDL_ControllerDeviceEvent evt;
                 evt.which = i;
                 controllerAdded(mFakeDeviceID, evt);
-                std::cout << "Detected game controller: " << SDL_GameControllerNameForIndex(i) << std::endl;
+                //Bug in FreeBSD's SDL? SDL_GameControllerNameForIndex returns NULL
+                std::cout << "Detected game controller" << std::endl;
             }
             else
             {
-                std::cout << "Detected unusable controller: " << SDL_JoystickNameForIndex(i) << std::endl;
+                //std::cout << "Detected unusable controller: " << SDL_JoystickNameForIndex(i) << std::endl;
             }
         }
 
