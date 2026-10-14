--- sources/qgimanager.cpp.orig	2026-01-28 12:19:13 UTC
+++ sources/qgimanager.cpp
@@ -70,25 +70,6 @@ void QGIManager::release(QGraphicsItem *qgi) {
 	}
 }
 
-/**
-	Demande au QGIManager de gerer plusieurs QGI
-	@param qgis QGraphicsItems a gerer
-*/
-void QGIManager::manage(const QList<QGraphicsItem *> &qgis) {
-	foreach(QGraphicsItem *qgi, qgis) manage(qgi);
-}
-
-/**
-	Indique au QGIManager que pour chaque QGI fourni, une reference vers celui-ci
-	a ete detruite.
-	S'il n'y a plus de references vers un QGI et que celui-ci n'est pas present
-	sur la scene de ce QGIManager, alors il sera detruit.
-	@param qgis QGraphicsItems a ne plus gerer
-*/
-void QGIManager::release(const QList<QGraphicsItem *> &qgis) {
-	foreach(QGraphicsItem *qgi, qgis) release(qgi);
-}
-
 void QGIManager::manage(const QVector<QGraphicsItem *> &items) {
 	for (const auto &qgi : items) {
 		manage(qgi);
