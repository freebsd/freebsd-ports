- workaround for https://gitlab.kitware.com/vtk/vtk/-/issues/18683

--- src/IVtkDraw/IVtkDraw_Interactor.cxx.orig	2021-10-30 11:13:52 UTC
+++ src/IVtkDraw/IVtkDraw_Interactor.cxx
@@ -26,6 +26,12 @@
 #ifdef AllValues
 #undef AllValues
 #endif
+#ifdef Status
+#undef Status
+#endif
+#ifdef Success
+#undef Success
+#endif
 
 #include <vtkXRenderWindowInteractor.h>
 #include <vtkXOpenGLRenderWindow.h>
