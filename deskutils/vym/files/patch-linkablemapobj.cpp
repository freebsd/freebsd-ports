--- linkablemapobj.cpp.orig	Tue Jan  4 10:49:50 2005
+++ linkablemapobj.cpp	Sat Jan 15 12:41:45 2005
@@ -1,4 +1,4 @@
-//#include <math.h>
+#include <math.h>
 
 #include "linkablemapobj.h"
 #include "branchobj.h"
@@ -456,10 +456,10 @@
 	double vy=p2y - p1y;
 
 	// Draw the horizontal line below heading (from ChildPos to ParPos)
-	bottomline->setPoints (lrint(childPos.x()),
-		lrint(childPos.y()),
-		lrint(p1x),
-		lrint(p1y) );
+	bottomline->setPoints ((long)rint(childPos.x()),
+		(long)rint(childPos.y()),
+		(long)rint(p1x),
+		(long)rint(p1y) );
 
 	double a;	// angle
 	if (vx > -0.000001 && vx < 0.000001)
@@ -467,7 +467,7 @@
 	else
 		a=atan( vy / vx );
 	// "turning point" for drawing polygonal links
-	QPoint tp (-lrint(sin (a)*thickness_start), lrint(cos (a)*thickness_start));	
+	QPoint tp (-(long)rint(sin (a)*thickness_start), (long)rint(cos (a)*thickness_start));	
 	
 	QCanvasLine *cl;
 
@@ -477,10 +477,10 @@
 	switch (style)
 	{
 		case StyleLine:
-			l->setPoints( lrint (parPos.x()),
-				lrint(parPos.y()),
-				lrint(p2x),
-				lrint(p2y) );
+			l->setPoints( (long)rint (parPos.x()),
+				(long)rint(parPos.y()),
+				(long)rint(p2x),
+				(long)rint(p2y) );
 			break;	
 		case StyleParabel:	
 			parabel (pa0, p1x,p1y,p2x,p2y);
@@ -492,15 +492,15 @@
 			}
 			break;
 		case StylePolyLine:
-			pa0[0]=QPoint (lrint(p2x+tp.x()), lrint(p2y+tp.y()));
-			pa0[1]=QPoint (lrint(p2x-tp.x()), lrint(p2y-tp.y()));
-			pa0[2]=QPoint (lrint (parPos.x()), lrint(parPos.y()) );
+			pa0[0]=QPoint ((long)rint(p2x+tp.x()), (long)rint(p2y+tp.y()));
+			pa0[1]=QPoint ((long)rint(p2x-tp.x()), (long)rint(p2y-tp.y()));
+			pa0[2]=QPoint ((long)rint (parPos.x()), (long)rint(parPos.y()) );
 			p->setPoints (pa0);
 			// here too, draw line to avoid missing pixels
-			l->setPoints( lrint (parPos.x()),
-				lrint(parPos.y()),
-				lrint(p2x),
-				lrint(p2y) );
+			l->setPoints( (long)rint (parPos.x()),
+				(long)rint(parPos.y()),
+				(long)rint(p2x),
+				(long)rint(p2y) );
 			break;
 		case StylePolyParabel:	
 			parabel (pa1, p1x,p1y,p2x+tp.x(),p2y+tp.y());
@@ -680,12 +680,12 @@
 		m=(vy / (vx*vx));
 	dx=vx/(arcsegs);
 	int i;
-	ya.setPoint (0,QPoint (lrint(p1x),lrint(p1y)));
+	ya.setPoint (0,QPoint ((long)rint(p1x),(long)rint(p1y)));
 	for (i=1;i<=arcsegs;i++)
 	{	
 		pnx=p1x+dx;
 		pny=m*(pnx-parPos.x())*(pnx-parPos.x())+parPos.y();
-		ya.setPoint (i,QPoint (lrint(pnx),lrint(pny)));
+		ya.setPoint (i,QPoint ((long)rint(pnx),(long)rint(pny)));
 		p1x=pnx;
 		p1y=pny;
 	}	
