--- gr-qtgui/lib/timeRasterGlobalData.cc.orig	2024-02-19 05:24:01 UTC
+++ gr-qtgui/lib/timeRasterGlobalData.cc
@@ -155,7 +155,13 @@ void TimeRasterData::setRange(const QwtDoubleInterval&
 {
     d_intensityRange = newRange;
 }
+#elif QWT_VERSION >= 0x060200
+void TimeRasterData::setInterval(Qt::Axis axis, const QwtInterval& interval)
+{
+    d_intervals[axis] = interval;
+}
 
+QwtInterval TimeRasterData::interval(Qt::Axis a) const { return d_intervals[a]; }
 #endif
 
 
