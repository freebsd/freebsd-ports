--- ./src/EyeBehavior.cpp.orig	Mon May 26 08:38:02 2003
+++ ./src/EyeBehavior.cpp	Sun Jun  8 22:14:17 2003
@@ -55,6 +55,7 @@
   EmAssert(table->getBall(2) != NULL, "Ball3 group NULL");
   EmAssert(this->getParent() != NULL, "Parent group NULL");
 
+#if EM_USE_SDL
   // short cuts for changing view F1, F2, F2, F4
   if (Keyboard::isKeyDown(SDLK_F1)) {
     Config::getInstance()->setView(0);
@@ -65,6 +66,7 @@
   } else if (Keyboard::isKeyDown(SDLK_F4)) {
     Config::getInstance()->setView(3);
   }
+#endif
 
   // the nudge code is here ----------------
   if (m_iNudgeTick < 1) {
