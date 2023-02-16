--- BambooTracker/gui/order_list_editor/order_list_panel.cpp.orig	2023-02-04 06:49:52 UTC
+++ BambooTracker/gui/order_list_editor/order_list_panel.cpp
@@ -709,9 +709,8 @@ void OrderListPanel::drawBorders(int maxWidth)
 	QPainter painter(&backPixmap_);
 	painter.setPen(palette_->odrBorderColor);
 	painter.drawLine(rowNumWidth_, 0, rowNumWidth_, backPixmap_.height());
-	for (int x = rowNumWidth_ + trackWidth_, trackVisIdx = leftTrackVisIdx_; x <= maxWidth; ++trackVisIdx) {
+	for (int x = rowNumWidth_ + trackWidth_; x <= maxWidth; x += trackWidth_) {
 		painter.drawLine(x, 0, x, backPixmap_.height());
-		x += trackWidth_;
 	}
 }
 
