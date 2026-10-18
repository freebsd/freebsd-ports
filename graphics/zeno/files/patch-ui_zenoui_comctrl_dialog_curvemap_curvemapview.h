--- ui/zenoui/comctrl/dialog/curvemap/curvemapview.h.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/dialog/curvemap/curvemapview.h
@@ -8,6 +8,7 @@ class CurveGrid;
 class CurveScalarItem;
 class CurveNodeItem;
 class CurveModel;
+Q_DECLARE_OPAQUE_POINTER(CurveNodeItem*)
 
 class CurveMapView : public QGraphicsView
 {
