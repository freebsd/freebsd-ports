--- InputManager.cpp.orig	2004-10-09 07:41:12.000000000 +0900
+++ InputManager.cpp	2015-05-06 22:08:05.341688383 +0900
@@ -164,7 +164,7 @@
 }
 
 int JoystickAxisSwitch::id() const {
-  return 3000 + which * 50 + axis + (maximum?1:0);
+  return 3000 + which * 50 + axis * 2 + (maximum?1:0);
 }
 
 bool JoystickAxisSwitch::isArrowUp()   const {
