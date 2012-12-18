--- ./src/fgui/glapparea.cpp.orig	2012-12-02 18:48:47.000000000 -0500
+++ ./src/fgui/glapparea.cpp	2012-12-02 18:58:20.000000000 -0500
@@ -23,6 +23,7 @@
 #include <qimage.h>
 #include <qtimer.h>
 #include <math.h>
+#include <GL/glu.h>
 
 
 GLAppArea::GLAppArea( QWidget* parent,QStringList* strlista)
