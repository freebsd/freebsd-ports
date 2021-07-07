--- src/IVtkDraw/IVtkDraw_Interactor.cxx.orig	2020-11-03 14:50:01 UTC
+++ src/IVtkDraw/IVtkDraw_Interactor.cxx
@@ -20,6 +20,13 @@
 #include <vtkWin32OpenGLRenderWindow.h>
 #else
 #include <GL/glx.h>
+
+// Preventing naming collisions between
+// GLX and VTK versions 9.0 and above
+#ifdef AllValues
+#undef AllValues
+#endif
+
 #include <vtkXRenderWindowInteractor.h>
 #include <vtkXOpenGLRenderWindow.h>
 #endif
