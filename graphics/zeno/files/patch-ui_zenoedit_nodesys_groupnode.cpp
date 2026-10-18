--- ui/zenoedit/nodesys/groupnode.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/nodesys/groupnode.cpp
@@ -96,7 +96,7 @@ void GroupTextItem::paint(QPainter *pain
     QString text = m_text;
     qreal width = ZenoStyle::scaleWidth(4);
     QRectF textRect = boundingRect().adjusted(width, 0, -width, 0);
-    if (fontMetrics.width(text) > textRect.width()) {
+    if (fontMetrics.horizontalAdvance(text) > textRect.width()) {
         text = fontMetrics.elidedText(text, Qt::ElideRight, textRect.width());
     }
     painter->drawText(textRect, Qt::AlignVCenter, text);
