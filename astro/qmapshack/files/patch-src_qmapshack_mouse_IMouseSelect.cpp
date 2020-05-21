--- src/qmapshack/mouse/IMouseSelect.cpp.orig	2020-05-21 11:11:11 UTC
+++ src/qmapshack/mouse/IMouseSelect.cpp
@@ -23,6 +23,7 @@
 #include "mouse/IScrOpt.h"
 
 #include <QtWidgets>
+#include <QPainterPath>
 
 IMouseSelect::IMouseSelect(CGisDraw *gis, CCanvas *canvas, CMouseAdapter *mouse)
     : IMouse(gis, canvas, mouse)
