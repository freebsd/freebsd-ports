--- source/cController.cpp.orig	2018-06-22 20:39:57 UTC
+++ source/cController.cpp
@@ -182,16 +182,16 @@ void cController::attackEnemy() {
     
     cObject* target = cWorld::instance->mIndex[entity];
     if (mDevice->inTargetRange() < 0.01) {
-        mDevice->do_aimFor(NULL);
+        mDevice->do_aimFor(0);
         pop();
         return;
     }
     if (target == NULL) { // Target disappeared
-        mDevice->do_aimFor(NULL);
+        mDevice->do_aimFor(0);
         pop();
         return;
     } else if (target->hasRole(DEAD)) {
-        mDevice->do_aimFor(NULL);
+        mDevice->do_aimFor(0);
         pop();
         return;
     }
