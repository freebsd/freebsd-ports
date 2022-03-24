--- gr-qtgui/include/gnuradio/qtgui/TimeRasterDisplayPlot.h.orig	2024-02-19 05:15:29 UTC
+++ gr-qtgui/include/gnuradio/qtgui/TimeRasterDisplayPlot.h
@@ -35,7 +35,9 @@
 #if QWT_VERSION < 0x060000
 #include <gnuradio/qtgui/plot_waterfall.h>
 #else
-#include <qwt_compat.h>
+#include <qwt_interval.h>
+
+typedef QwtInterval QwtDoubleInterval;
 #endif
 
 /*!
