--- src/EyeBehavior.cpp.orig	2018-03-24 23:40:31 UTC
+++ src/EyeBehavior.cpp
@@ -56,6 +56,7 @@ void EyeBehavior::onTick() {
   EmAssert(table->getBall(2) != NULL, "Ball3 group NULL");
   EmAssert(this->getParent() != NULL, "Parent group NULL");
 
+#if EM_USE_SDL
   // shortcuts for changing view F1, F2, F2, F4 // now F5 F6 F7 F8
   // I changed to F5 F6 F7 F8 to use the Alt+F4 quit shortcut //!rzr
   if (Keyboard::isKeyDown(SDLK_F5)) {
@@ -71,6 +72,7 @@ void EyeBehavior::onTick() {
   } else if (Keyboard::isKeyDown(SDLK_F10)) { //rotated screen 
     Config::getInstance()->setView(5);
   }
+#endif
 
   // the nudge code is here ----------------
   if (m_iNudgeTick < 1) {
