--- src/meshview.cpp	2009/12/17 19:54:48	66
+++ src/meshview.cpp	2012/04/03 22:32:00	74
@@ -16,6 +16,8 @@
 # define M_PI 3.14159265358979323846
 #endif
 
+#include <GL/glu.h>
+
 #include <QMouseEvent>
 #include <QWheelEvent>
 #include <QKeyEvent>
