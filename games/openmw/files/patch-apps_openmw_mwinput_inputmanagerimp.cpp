--- apps/openmw/mwinput/inputmanagerimp.cpp.orig	2016-01-12 16:11:28 UTC
+++ apps/openmw/mwinput/inputmanagerimp.cpp
@@ -119,11 +119,12 @@ namespace MWInput
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
 
@@ -389,6 +390,8 @@ namespace MWInput
             {
                 float xAxis = mInputBinder->getChannel(A_MoveLeftRight)->getValue()*2.0f-1.0f;
                 float yAxis = mInputBinder->getChannel(A_MoveForwardBackward)->getValue()*2.0f-1.0f;
+                if (mInvertY)
+                    yAxis *= -1;
                 float zAxis = mInputBinder->getChannel(A_LookUpDown)->getValue()*2.0f-1.0f;
                 const MyGUI::IntSize& viewSize = MyGUI::RenderManager::getInstance().getViewSize();
 
@@ -456,13 +459,13 @@ namespace MWInput
                     {
                         triedToMove = true;
                         mPlayer->setAutoMove (false);
-                        mPlayer->setForwardBackward (1);
+                        mPlayer->setForwardBackward (mInvertY ? -1 : 1);
                     }
                     else if (yAxis > .5)
                     {
                         triedToMove = true;
                         mPlayer->setAutoMove (false);
-                        mPlayer->setForwardBackward (-1);
+                        mPlayer->setForwardBackward (mInvertY ? 1 : -1);
                     }
 
                     else if(mPlayer->getAutoMove())
