--- src/EyeBehavior.cpp.orig	Thu Nov 20 17:46:17 2003
+++ src/EyeBehavior.cpp	Thu Dec 11 21:02:38 2003
@@ -56,6 +56,7 @@
   EmAssert(table->getBall(2) != NULL, "Ball3 group NULL");
   EmAssert(this->getParent() != NULL, "Parent group NULL");
 
+#if EM_USE_SDL
   // shortcuts for changing view F1, F2, F2, F4 // now F5 F6 F7 F8
   // I changed to F5 F6 F7 F8 to use the Alt+F4 quit shortcut //!rzr
   if (Keyboard::isKeyDown(SDLK_F5)) {
@@ -67,6 +68,7 @@
   } else if (Keyboard::isKeyDown(SDLK_F8)) {
     Config::getInstance()->setView(3);
   }
+#endif
 
   // the nudge code is here ----------------
   if (m_iNudgeTick < 1) {
