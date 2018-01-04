--- src/fgui/glapparea.cpp.orig	2016-03-24 23:43:09 UTC
+++ src/fgui/glapparea.cpp
@@ -23,6 +23,7 @@
 #include <qimage.h>
 #include <qtimer.h>
 #include <math.h>
+#include <GL/glu.h>
 
 
 GLAppArea::GLAppArea( QWidget* parent,QStringList* strlista)
