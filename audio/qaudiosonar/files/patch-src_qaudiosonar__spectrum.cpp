--- src/qaudiosonar_spectrum.cpp.orig	2022-11-16 11:15:31 UTC
+++ src/qaudiosonar_spectrum.cpp
@@ -68,7 +68,7 @@ QasBand :: getText(QMouseEvent *event)
 QString
 QasBand :: getText(QMouseEvent *event)
 {
-	int key = (9 + (12 * event->x()) / width()) % 12;
+	int key = (9 + (12 * event->position().toPoint().x()) / width()) % 12;
 
 	return (QString(qas_key_map[key]).arg(5));
 }
@@ -172,7 +172,7 @@ QasBand :: mousePressEvent(QMouseEvent *event)
 	} else if (event->button() == Qt::MiddleButton) {
 		ps->edit->appendPlainText(getText(event));
 	} else if (event->button() == Qt::LeftButton) {
-		ps->edit->appendPlainText(getFullText(event->y()));
+		ps->edit->appendPlainText(getFullText(event->position().toPoint().y()));
 	}
 	event->accept();
 }
@@ -270,14 +270,14 @@ QasGraph :: getText(QMouseEvent *event)
 QasGraph :: getText(QMouseEvent *event)
 {
 	const QasZoomRange &wc_range = ps->zoom_range[ps->zoom_level];
-	int graph = (3 * event->y()) / height();
+	int graph = (3 * event->position().toPoint().y()) / height();
 	int band;
 	int key;
 
 	switch (graph) {
 	case 0:
 	case 1:
-		band = (qas_num_bands * event->x()) / width();
+		band = (qas_num_bands * event->position().toPoint().x()) / width();
 		if (band > -1 && band < (int)qas_num_bands) {
 			band -= band % QAS_WAVE_STEP;
 			return QString(qas_descr_table[band]) +
@@ -286,7 +286,7 @@ QasGraph :: getText(QMouseEvent *event)
 			return QString();
 		}
 	default:
-		key = (event->x() * (1 + wc_range.stop - wc_range.start)) / width() + wc_range.start;
+		key = (event->position().toPoint().x() * (1 + wc_range.stop - wc_range.start)) / width() + wc_range.start;
 		/* range check */
 		if (key < 0)
 			key = 0;
