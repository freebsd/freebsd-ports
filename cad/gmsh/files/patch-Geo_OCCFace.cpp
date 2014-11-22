--- Geo/OCCFace.cpp.orig	2014-02-07 08:31:21.000000000 +0100
+++ Geo/OCCFace.cpp	2014-11-18 23:35:55.000000000 +0100
@@ -28,7 +28,11 @@
 #include <BRepMesh_FastDiscret.hxx>
 
 #if (OCC_VERSION_MAJOR == 6) && (OCC_VERSION_MINOR >= 6)
-#include <BOPInt_Context.hxx>
+#  if (OCC_VERSION_MINOR < 8)
+#  include <BOPInt_Context.hxx>
+#  else
+#  include <IntTools_Context.hxx>
+#  endif
 #include <BOPTools_AlgoTools2D.hxx>
 #include <BOPTools_AlgoTools.hxx>
 #else
@@ -455,7 +459,7 @@
 void OCCFace::replaceEdgesInternal(std::list<GEdge*> &new_edges)
 {
 
-#if (OCC_VERSION_MAJOR == 6) && (OCC_VERSION_MINOR >= 6)
+#if (OCC_VERSION_MAJOR == 6) && (OCC_VERSION_MINOR >= 6) && (OCC_VERSION_MINOR < 8)
   Handle(BOPInt_Context) myContext = new BOPInt_Context;
 #elif defined(OCC_VERSION_HEX) && OCC_VERSION_HEX >= 0x060503
   Handle(IntTools_Context) myContext = new IntTools_Context;
