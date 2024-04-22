--- gr-qtgui/lib/ConstellationDisplayPlot.cc.orig	2024-02-19 05:20:52 UTC
+++ gr-qtgui/lib/ConstellationDisplayPlot.cc
@@ -29,6 +29,7 @@
 #include <qwt_scale_draw.h>
 #include <QColor>
 #include <iostream>
+#include <cmath>
 
 class ConstellationDisplayZoomer : public QwtPlotZoomer
 {
