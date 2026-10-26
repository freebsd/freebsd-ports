-- workaround for https://gitlab.kitware.com/vtk/vtk/-/work_items/20221

--- src/Draw/TKIVtkDraw/IVtkDraw/IVtkDraw.cxx.orig	2026-10-25 20:42:17 UTC
+++ src/Draw/TKIVtkDraw/IVtkDraw/IVtkDraw.cxx
@@ -74,6 +74,9 @@
 #include <vtkRenderWindowInteractor.h>
 #include <vtkSmartPointer.h>
 #include <vtkTIFFWriter.h>
+#ifdef AllValues
+  #undef AllValues
+#endif
 #include <vtkWindowToImageFilter.h>
 #ifndef _WIN32
   #include <X11/X.h>
