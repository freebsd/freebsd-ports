--- library/tulip-ogl/src/Glyph.cpp.orig	Tue Jan 28 16:44:37 2003
+++ library/tulip-ogl/src/Glyph.cpp	Fri Oct 29 14:14:08 2004
@@ -16,7 +16,8 @@
     LOD=gc->LOD;
   }
   else {
-    (void *)superGraph = (void *)glGraph = (void *)NULL;
+    superGraph = NULL;
+    glGraph = NULL;
     LOD=LOF=0;
   }
 }
