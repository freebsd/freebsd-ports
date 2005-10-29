--- src/coastmap.cpp	Mon Jul 18 16:19:30 2005
+++ src/coastmap.cpp	Fri Oct 28 15:30:30 2005
@@ -1316,7 +1316,7 @@
 	maph = surf->h;
 	pixelw_real = realwidth/mapw;
 	realheight = maph*realwidth/mapw;
-	pixels_per_seg = 1 << unsigned(ceil(log2(60000/pixelw_real)));
+	pixels_per_seg = 1 << unsigned(ceil(log(60000/pixelw_real)));
 	segsx = mapw/pixels_per_seg;
 	segsy = maph/pixels_per_seg;
 	segw_real = pixelw_real * pixels_per_seg;
