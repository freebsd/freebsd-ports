--- src/core/RBlockReferenceEntity.cpp.orig	2017-06-18 19:08:03.431567000 +0200
+++ src/core/RBlockReferenceEntity.cpp	2017-06-18 19:08:31.008331000 +0200
@@ -418,5 +418,5 @@
                     QStack<REntity*> blockRefStack = e.getBlockRefViewportStack();
                     bool skip = false;
-                    for (int i=blockRefStack.length()-1; i>=0; i--) {
+                    for (int i=blockRefStack.size()-1; i>=0; i--) {
                         REntity* ent = blockRefStack.at(i);
                         RBlockReferenceEntity* blockRef = dynamic_cast<RBlockReferenceEntity*>(ent);
