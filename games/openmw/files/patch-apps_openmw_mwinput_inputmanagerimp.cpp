--- apps/openmw/mwinput/inputmanagerimp.cpp.orig	2015-11-22 18:54:17 UTC
+++ apps/openmw/mwinput/inputmanagerimp.cpp
@@ -374,6 +374,8 @@ namespace MWInput
             {
                 float xAxis = mInputBinder->getChannel(A_MoveLeftRight)->getValue()*2.0f-1.0f;
                 float yAxis = mInputBinder->getChannel(A_MoveForwardBackward)->getValue()*2.0f-1.0f;
+                if (mInvertY)
+                    yAxis *= -1;
                 float zAxis = mInputBinder->getChannel(A_LookUpDown)->getValue()*2.0f-1.0f;
                 const MyGUI::IntSize& viewSize = MyGUI::RenderManager::getInstance().getViewSize();
 
@@ -441,13 +443,13 @@ namespace MWInput
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
