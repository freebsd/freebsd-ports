--- radiant/brushmanip.cpp.orig	Sat Feb 11 20:57:16 2006
+++ radiant/brushmanip.cpp	Sun Dec 17 17:03:49 2006
@@ -416,7 +416,7 @@
   }
   void visit(FaceInstance& face) const
   {
-    if(face.isSelected(SelectionSystem::eFace))
+    if(face.isSelected())
     {
       m_visitor.visit(face.getFace());
     }
