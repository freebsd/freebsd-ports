--- poppler/CairoOutputDev.cc.orig	Thu Mar  3 03:10:24 2005
+++ poppler/CairoOutputDev.cc	Thu Mar  3 03:10:58 2005
@@ -240,7 +240,7 @@
     if (subpath->getNumPoints() > 0) {
       state->transform(subpath->getX(0), subpath->getY(0), &x1, &y1);
       if (snapToGrid) {
-	x1 = round (x1); y1 = round (y1);
+	x1 = rint (x1); y1 = rint (y1);
       }
       cairo_move_to (cairo, x1, y1);
       LOG (printf ("move_to %f, %f\n", x1, y1));
@@ -248,9 +248,9 @@
       while (j < subpath->getNumPoints()) {
 	if (subpath->getCurve(j)) {
 	  if (snapToGrid) {
-	    x1 = round (x1); y1 = round (y1);
-	    x2 = round (x2); y2 = round (y2);
-	    x3 = round (x3); y3 = round (y3);
+	    x1 = rint (x1); y1 = rint (y1);
+	    x2 = rint (x2); y2 = rint (y2);
+	    x3 = rint (x3); y3 = rint (y3);
 	  }
 	  state->transform(subpath->getX(j), subpath->getY(j), &x1, &y1);
 	  state->transform(subpath->getX(j+1), subpath->getY(j+1), &x2, &y2);
@@ -264,7 +264,7 @@
 	} else {
 	  state->transform(subpath->getX(j), subpath->getY(j), &x1, &y1);
 	  if (snapToGrid) {
-	    x1 = round (x1); y1 = round (y1);
+	    x1 = rint (x1); y1 = rint (y1);
 	  }
 	  cairo_line_to (cairo, x1, y1);
 	  LOG(printf ("line_to %f, %f\n", x1, y1));
