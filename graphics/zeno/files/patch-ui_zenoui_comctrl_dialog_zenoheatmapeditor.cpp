--- ui/zenoui/comctrl/dialog/zenoheatmapeditor.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/dialog/zenoheatmapeditor.cpp
@@ -382,7 +382,7 @@ void SVColorView::paintEvent(QPaintEvent
 	painter.fillRect(rect, linearGradientV);
 
 	static const int nLenSelector = ZenoStyle::dpiScaled(6);
-	qreal h = 0, s = 0, v = 0;
+	float h = 0, s = 0, v = 0;
 	m_color.getHsvF(&h, &s, &v);
 	QPointF center(s * this->width(), (1 - v) * this->height());
 	painter.setPen(QPen(QColor(0,0,0)));
