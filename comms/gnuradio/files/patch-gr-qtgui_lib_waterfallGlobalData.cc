--- gr-qtgui/lib/waterfallGlobalData.cc.orig	2024-02-19 05:24:33 UTC
+++ gr-qtgui/lib/waterfallGlobalData.cc
@@ -158,7 +158,13 @@ void WaterfallData::setRange(const QwtDoubleInterval& 
 {
     _intensityRange = newRange;
 }
+#elif QWT_VERSION >= 0x060200
+void WaterfallData::setInterval(Qt::Axis axis, const QwtInterval& interval)
+{
+    d_intervals[axis] = interval;
+}
 
+QwtInterval WaterfallData::interval(Qt::Axis a) const { return d_intervals[a]; }
 #endif
 
 
