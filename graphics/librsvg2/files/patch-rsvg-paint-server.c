--- rsvg-paint-server.c.orig	Tue Mar 30 13:48:53 2004
+++ rsvg-paint-server.c	Tue Mar 30 13:49:10 2004
@@ -150,6 +150,9 @@
 	double dx, dy, scale;
 	double affine[6];
 	int i;
+	float xchange, ychange, pointlen,unitlen;
+	float nx2, ny2;
+	float x0, y0;
 
 	agl = z->agl;
 	if (agl == NULL)
@@ -180,9 +183,6 @@
 
 	art_affine_multiply(affine, rlg->affine, affine);
 
-	float xchange, ychange, pointlen,unitlen;
-	float nx2, ny2;
-	float x0, y0;
 
 	xchange = rlg->x2 - rlg->x1;
 	ychange = rlg->y2 - rlg->y1;
