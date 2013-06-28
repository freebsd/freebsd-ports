--- src/graphics/vector/beziercurve.cpp.orig	2013-06-26 10:46:07.000000000 +0200
+++ src/graphics/vector/beziercurve.cpp	2013-06-26 10:40:02.000000000 +0200
@@ -700,9 +700,9 @@
 	R1.setTopLeft(P1); R1.setBottomRight(Q1);
 	R2.setTopLeft(P2); R2.setBottomRight(Q2);
 	
-	//QPointF intersectionPoint = QPointF(50.0, 50.0); // bogus point
-	//QPointF* intersection = &intersectionPoint;
-	QPointF* cubicIntersection = &QPointF(50.0, 50.0); // bogus point
+	QPointF tmpIntersectionPoint = QPointF(50.0, 50.0); // bogus point
+	QPointF* cubicIntersection = &tmpIntersectionPoint;
+	//QPointF* cubicIntersection = &QPointF(50.0, 50.0); // bogus point
 	if( R1.intersects(R2) || L2.intersect(L1, cubicIntersection) == QLineF::BoundedIntersection ) {
 	//if(L2.intersect(L1, intersection) == QLineF::BoundedIntersection) {
 		//qDebug() << "                   FOUND rectangle intersection ";
