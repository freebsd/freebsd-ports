--- src/EyeBehavior.cpp.orig	2020-12-18 16:34:55 UTC
+++ src/EyeBehavior.cpp
@@ -57,6 +57,7 @@ void EyeBehavior::onTick() {
   EmAssert(table->getBall(2) != NULL, "Ball3 group NULL");
   EmAssert(this->getParent() != NULL, "Parent group NULL");
 
+#if EM_USE_SDL
   // shortcuts for changing view F1, F2, F2, F4 // now F5 F6 F7 F8
   // I changed to F5 F6 F7 F8 to use the Alt+F4 quit shortcut //!rzr
   if (Keyboard::isKeyDown(SDLK_F5)) {
@@ -68,6 +69,7 @@ void EyeBehavior::onTick() {
   } else if (Keyboard::isKeyDown(SDLK_F8)) {
     Config::getInstance()->setView(3);
   }
+#endif
 
   // the nudge code is here ----------------
   if (m_iNudgeTick < 1) {
