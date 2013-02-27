--- kalarm/lib/spinbox2.cpp
+++ kalarm/lib/spinbox2.cpp
@@ -28,7 +28,7 @@
 #include <QMouseEvent>
 #include <QStyleOptionSpinBox>
 #include <QGraphicsPixmapItem>
-#include <QPaintEngine>
+#include <QPainter>
 #include <QTimer>
 #include <QFrame>
 #include <QBrush>
@@ -588,8 +588,9 @@ void SpinMirror::setFrame()
 		p = grabWidget(mMainSpinbox, QRect(x, 0, 1, height()));
 		// Blot out edit field stuff from the middle of the slice
 		QPixmap dot = grabWidget(mMainSpinbox, QRect(x, editOffsetY, 1, 1));
-		QPaintEngine* pe = p.paintEngine();
-		pe->drawTiledPixmap(QRectF(0, editOffsetY, 1, height() - 2*editOffsetY), dot, QPointF(0, 0));
+		QPainter painter(&p);
+		painter.drawTiledPixmap(0, editOffsetY, 1, height() - 2*editOffsetY, dot, 0, 0);
+		painter.end();
 		// Horizontally fill the mirror widget with the vertical slice
 		p = p.scaled(size());
 		// Grab the left hand border of the main spinbox, and draw it into the mirror widget.
