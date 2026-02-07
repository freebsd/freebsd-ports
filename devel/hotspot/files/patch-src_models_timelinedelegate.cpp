--- src/models/timelinedelegate.cpp.orig	2024-05-28 14:02:14 UTC
+++ src/models/timelinedelegate.cpp
@@ -194,7 +194,7 @@ void TimeLineDelegate::paint(QPainter* painter, const 
         painter->drawRect(threadTimeRect.adjusted(-1, -1, 0, 0));
 
         // visualize all events
-        painter->setBrush({});
+        painter->setBrush(QBrush());
 
         if (offCpuCostId != -1) {
             const auto offCpuColor = scheme.background(KColorScheme::NegativeBackground).color();
