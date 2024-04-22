- workaround for https://gitlab.kitware.com/vtk/vtk/-/issues/18683

--- src/IVtkDraw/IVtkDraw_Interactor.cxx.orig	2023-12-04 15:53:08 UTC
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
 
 // Resolve name collisions with X11 headers
 #ifdef Status
