--- ui/zenoedit/panel/zenoproppanel.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/panel/zenoproppanel.cpp
@@ -852,7 +852,7 @@ void ZenoPropPanel::getDelfCurveData(CUR
 
 void ZenoPropPanel::updateHandler(CURVE_DATA &curve) {
     if (curve.points.size() > 1) {
-        qSort(curve.points.begin(), curve.points.end(),
+        std::sort(curve.points.begin(), curve.points.end(),
               [](const CURVE_POINT &p1, const CURVE_POINT &p2) { return p1.point.x() < p2.point.x(); });
         float preX = curve.points.at(0).point.x();
         for (int i = 1; i < curve.points.size(); i++) {
