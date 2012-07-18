--- src/texture.c.orig	2008-04-06 16:37:29.000000000 +0200
+++ src/texture.c	2012-05-20 11:27:24.000000000 +0200
@@ -99,19 +99,19 @@
 static void average_RGBA_alpha_and_floor(unsigned char *image,
     int x, int y, int flr)
 {
-	int ir, ig, ib, ia, i, new_alpha;
+	int ir, ig, ib, ia, i;
 
 	for (i = 0; i < x * y * 4; i += 4) {
 		ir = image[i];
 		ig = image[i+1];
 		ib = image[i+2];
-		ia = image[i+3];
+		/* ia = image[i+3]; */
 
-		new_alpha = (ir + ig + ib) / 3;
-		if (new_alpha < flr)
-			new_alpha = 0;
+		ia = (ir + ig + ib) / 3;
+		if (ia < flr)
+			ia = 0;
 
-		image[i+3] = new_alpha;
+		image[i+3] = ia;
 	}
 
 	return;
