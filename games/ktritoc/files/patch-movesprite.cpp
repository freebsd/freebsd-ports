--- ktritoc/ktritoc/movesprite.cpp.orig	Wed Oct 22 02:37:18 2003
+++ ktritoc/ktritoc/movesprite.cpp	Wed Oct 22 02:37:33 2003
@@ -93,7 +93,7 @@
 }
 
 // Type = 0: cycle, 1: oscillate
-void MoveSprite::setAnimation(int delay=1, int type)
+void MoveSprite::setAnimation(int delay, int type)
 {
   mAnimDelay = delay;
   mAnimCount = 0;
