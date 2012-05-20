--- src/fgui/glapparea.cpp~	2012-05-19 22:54:35.000000000 -0300
+++ src/fgui/glapparea.cpp	2012-05-19 22:54:50.000000000 -0300
@@ -24,6 +24,8 @@
 #include <qtimer.h>
 #include <math.h>
 
+#include <GL/glu.h>
+
 
 GLAppArea::GLAppArea( QWidget* parent,QStringList* strlista)
     : QGLWidget( parent)
