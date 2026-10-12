-- Qt6 compatibility, see https://github.com/drawpile/Drawpile/issues/1600

--- src/desktop/widgets/tablettest.cpp.orig	2026-10-12 04:51:08 UTC
+++ src/desktop/widgets/tablettest.cpp
@@ -66,7 +66,7 @@ void TabletTester::mouseMoveEvent(QMouseEvent *e)
 	emit eventReport(QString("Mouse move X=%1 Y=%2 B=%3")
 						 .arg(mousePos.x())
 						 .arg(mousePos.y())
-						 .arg(e->buttons()));
+						 .arg(static_cast<int>(e->buttons())));
 	m_mousePath << e->pos();
 	update();
 }
@@ -118,7 +118,7 @@ void TabletTester::tabletEvent(QTabletEvent *e)
 	msg += QString(" X=%1 Y=%2 B=%3 P=%4% XT=%5° YT=%6° R=%7° T=%8 %9")
 			   .arg(posF.x(), 0, 'f', 2)
 			   .arg(posF.y(), 0, 'f', 2)
-			   .arg(e->buttons())
+			   .arg(static_cast<int>(e->buttons()))
 			   .arg(e->pressure() * 100, 0, 'f', 1)
 			   .arg(e->xTilt())
 			   .arg(e->yTilt())
