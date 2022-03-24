--- gr-qtgui/include/gnuradio/qtgui/plot_waterfall.h.orig	2024-02-19 05:17:32 UTC
+++ gr-qtgui/include/gnuradio/qtgui/plot_waterfall.h
@@ -28,8 +28,10 @@
 #include <qwt_plot_rasteritem.h>
 
 #if QWT_VERSION >= 0x060000
-#include <qwt_compat.h>
-#include <qwt_point_3d.h> // doesn't seem necessary, but is...
+#include <qsize.h>
+#include <qwt_interval.h>
+
+typedef QwtInterval QwtDoubleInterval;
 #endif
 
 class QwtColorMap;
