--- tools/tiff2ps.c	Thu Oct 14 13:53:28 2004
+++ tools/tiff2ps.c	Mon Nov 15 10:05:30 2004
@@ -412,5 +412,5 @@
 setupPageState(TIFF* tif, uint32* pw, uint32* ph, double* pprw, double* pprh)
 {
-	double xres = 0.0, yres = 0.0;
+	float xres = 0.0, yres = 0.0;
 
 	TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, pw);
@@ -543,5 +543,6 @@
 {
 	uint32 w, h;
-	double ox, oy, prw, prh;
+	float ox, oy;
+	double prw, prh;
 	double scale = 1.0;
 	double left_offset = lm * PS_UNIT_SIZE;
