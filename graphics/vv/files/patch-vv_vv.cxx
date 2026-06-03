Update for VTK 9 and fix platform-specific code.

- Replace QVTKOpenGLWidget with QVTKOpenGLNativeWidget (VTK 9 API change)
- Wrap Windows-specific #pragma in #ifdef _WIN32 to prevent linking errors
  on non-Windows platforms

--- vv/vv.cxx.orig	2025-04-17 12:54:38 UTC
+++ vv/vv.cxx
@@ -43,7 +43,7 @@
 #include "vvToolsList.h"
 #include "vvConfiguration.h"
 #if (VTK_MAJOR_VERSION == 8 && VTK_MINOR_VERSION >= 2) || VTK_MAJOR_VERSION >= 9
-#include <QVTKOpenGLWidget.h>
+#include <QVTKOpenGLNativeWidget.h>
 #endif
 
 #include <vtkFileOutputWindow.h>
@@ -56,7 +56,9 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <errno.h>
+#ifdef _WIN32
 #pragma comment(lib, "ws2_32.lib")
+#endif
 
 typedef enum {O_BASE,O_OVERLAY,O_FUSION,O_VF,O_CONTOUR,O_LANDMARKS} OpenModeType;
 typedef enum {P_NORMAL,P_SEQUENCE,P_WINDOW,P_LEVEL} ParseModeType;
@@ -119,7 +121,7 @@ int main( int argc, char** argv )
 #endif
 
 #if (VTK_MAJOR_VERSION == 8 && VTK_MINOR_VERSION >= 2) || VTK_MAJOR_VERSION >= 9
-  QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());
+  QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());
 #endif
   CLITK_INIT;
 
