--- src/waterfall/raster.cxx.orig	2018-02-24 13:42:49 UTC
+++ src/waterfall/raster.cxx
@@ -169,6 +169,10 @@ void Raster::resize(int x, int y, int w, int h)
 	while ((Ndest * rhs) < Hdest) Ndest++;
 	Ndest--;
 
+	if (Wdest < 0)
+		Wdest = 0;
+	if (Hdest < 0)
+		Hdest = 0;
 	unsigned char *tempbuf = new unsigned char [Wdest * Hdest];
 	unsigned char *oldbuf = vidbuf;
 
