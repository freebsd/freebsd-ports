--- gr-qtgui/include/gnuradio/qtgui/timeRasterGlobalData.h.orig	2024-02-19 05:18:25 UTC
+++ gr-qtgui/include/gnuradio/qtgui/timeRasterGlobalData.h
@@ -27,8 +27,9 @@
 #include <qwt_raster_data.h>
 
 #if QWT_VERSION >= 0x060000
-#include <qwt_compat.h>
-#include <qwt_point_3d.h> // doesn't seem necessary, but is...
+#include <qwt_interval.h>
+
+typedef QwtInterval QwtDoubleInterval;
 #endif
 
 class TimeRasterData : public QwtRasterData
@@ -47,6 +48,9 @@ class TimeRasterData : public QwtRasterData (public)
 #if QWT_VERSION < 0x060000
     virtual QwtDoubleInterval range() const;
     virtual void setRange(const QwtDoubleInterval&);
+#elif QWT_VERSION >= 0x060200
+    virtual QwtInterval interval(Qt::Axis) const;
+    void setInterval(Qt::Axis, const QwtInterval&);
 #endif
 
     virtual double value(double x, double y) const;
@@ -68,6 +72,10 @@ class TimeRasterData : public QwtRasterData (public)
     QwtDoubleInterval d_intensityRange;
 #else
     QwtInterval d_intensityRange;
+#endif
+
+#if QWT_VERSION >= 0x060200
+    QwtInterval d_intervals[3];
 #endif
 
 private:
