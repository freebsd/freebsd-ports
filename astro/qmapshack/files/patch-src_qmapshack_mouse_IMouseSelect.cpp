--- src/qmapshack/mouse/IMouseSelect.cpp.orig	2021-05-24 09:18:08 UTC
+++ src/qmapshack/mouse/IMouseSelect.cpp
@@ -24,6 +24,7 @@
 
 #include <QPainterPath>
 #include <QtWidgets>
+#include <QPainterPath>
 
 IMouseSelect::IMouseSelect(CGisDraw* gis, CCanvas* canvas, CMouseAdapter* mouse)
     : IMouse(gis, canvas, mouse)
