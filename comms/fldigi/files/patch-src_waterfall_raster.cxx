--- src/waterfall/raster.cxx.orig	2018-08-11 23:26:43 UTC
+++ src/waterfall/raster.cxx
@@ -169,6 +169,10 @@ void Raster::resize(int x, int y, int w,
 	while ((Ndest * rhs) < Hdest) Ndest++;
 	Ndest--;
 
+	if (Wdest < 0)
+		Wdest = 0;
+	if (Hdest < 0)
+		Hdest = 0;
 	unsigned char *tempbuf = new unsigned char [Wdest * Hdest];
 	unsigned char *oldbuf = vidbuf;
 
