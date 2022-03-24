--- gr-qtgui/include/gnuradio/qtgui/waterfallGlobalData.h.orig	2024-02-19 05:19:43 UTC
+++ gr-qtgui/include/gnuradio/qtgui/waterfallGlobalData.h
@@ -27,8 +27,9 @@
 #include <qwt_raster_data.h>
 
 #if QWT_VERSION >= 0x060000
-#include <qwt_compat.h>
-#include <qwt_point_3d.h> // doesn't seem necessary, but is...
+#include <qwt_interval.h>
+
+typedef QwtInterval QwtDoubleInterval;
 #endif
 
 class WaterfallData : public QwtRasterData
@@ -48,6 +49,9 @@ class WaterfallData : public QwtRasterData (public)
 #if QWT_VERSION < 0x060000
     virtual QwtDoubleInterval range() const;
     virtual void setRange(const QwtDoubleInterval&);
+#elif QWT_VERSION >= 0x060200
+    virtual QwtInterval interval(Qt::Axis) const;
+    void setInterval(Qt::Axis, const QwtInterval&);
 #endif
 
     virtual double value(double x, double y) const;
@@ -72,6 +76,10 @@ class WaterfallData : public QwtRasterData (public)
     QwtDoubleInterval _intensityRange;
 #else
     QwtInterval _intensityRange;
+#endif
+
+#if QWT_VERSION >= 0x060200
+    QwtInterval d_intervals[3];
 #endif
 
 private:
