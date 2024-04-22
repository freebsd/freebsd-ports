--- gr-qtgui/include/gnuradio/qtgui/DisplayPlot.h.orig	2024-02-19 05:15:00 UTC
+++ gr-qtgui/include/gnuradio/qtgui/DisplayPlot.h
@@ -41,7 +41,10 @@
 #include <vector>
 
 #if QWT_VERSION >= 0x060000
-#include <qwt_compat.h>
+typedef QPointF QwtDoublePoint;
+typedef QRectF QwtDoubleRect;
+
+typedef QwtInterval QwtDoubleInterval;
 #endif
 
 typedef QList<QColor> QColorList;
