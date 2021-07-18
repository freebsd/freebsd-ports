--- src/IVtkDraw/IVtkDraw.cxx.orig	2020-11-03 14:50:01 UTC
+++ src/IVtkDraw/IVtkDraw.cxx
@@ -36,6 +36,12 @@
 #include <V3d_TypeOfOrientation.hxx>
 #include <Aspect_DisplayConnection.hxx>
 
+// Preventing naming collisions between
+// GLX and VTK versions 9.0 and above
+#ifdef AllValues
+#undef AllValues
+#endif
+
 #include <IVtk_Types.hxx>
 #include <IVtkVTK_ShapeData.hxx>
 #include <IVtkOCC_Shape.hxx>
