diff -u -p -r1.43 libtiff/tif_getimage.c
--- libtiff/tif_getimage.c	19 Dec 2004 17:11:17 -0000	1.43
+++ libtiff/tif_getimage.c	24 Dec 2004 09:30:18 -0000
@@ -247,7 +247,7 @@ TIFFRGBAImageBegin(TIFFRGBAImage* img, T
     TIFFGetFieldDefaulted(tif, TIFFTAG_SAMPLESPERPIXEL, &img->samplesperpixel);
     TIFFGetFieldDefaulted(tif, TIFFTAG_EXTRASAMPLES,
 	&extrasamples, &sampleinfo);
-    if (extrasamples > 1)
+    if (extrasamples >= 1)
     {
 	switch (sampleinfo[0]) {
 	case EXTRASAMPLE_UNSPECIFIED:	/* Workaround for some images without */
