
--- tools/fax2ps.c.orig	Tue Sep  2 19:54:34 1997
+++ tools/fax2ps.c	Sat Feb 13 16:43:01 1999
@@ -151,7 +151,7 @@
 {
     uint32 w, h;
     uint16 unit;
-    float xres, yres;
+    float xres, yres, scale = 1.0;
     tstrip_t s, ns;
 
     TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &h);
@@ -174,21 +174,13 @@
 
     printf("%%%%Page: \"%d\" %d\n", pageNumber, pageNumber);
     printf("/$pageTop save def gsave\n");
-    if (scaleToPage) {
-	float yscale = pageHeight / (h/yres);
-	float xscale = pageWidth / (w/xres);
-	printf("%d %d translate\n",
-               (int) (((basePageWidth - pageWidth) * points) * half),
-               (int)((yscale*(h/yres)*points) +
-               (basePageHeight - pageHeight) * points * half)  );
-	printf("%g %g scale\n", (72.*xscale)/xres, -(72.*yscale)/yres);
-    } else {
-	printf("%d %d translate\n",
-               (int) ((basePageWidth - pageWidth) * points * half),
-               (int)((72.*h/yres) +
-               (basePageHeight - pageHeight) * points * half) );
-	printf("%g %g scale\n", 72./xres, -72./yres);
-    }
+    if (scaleToPage)
+	scale = pageHeight / (h/yres) < pageWidth / (w/xres) ?
+		pageHeight / (h/yres) : pageWidth / (w/xres);
+    printf("%g %g translate\n",
+           points * (pageWidth - scale*w/xres) * half,
+           points * (scale*h/yres + (pageHeight - scale*h/yres) * half));
+    printf("%g %g scale\n", points/xres*scale, -points/yres*scale);
     printf("0 setgray\n");
     TIFFSetField(tif, TIFFTAG_FAXFILLFUNC, printruns);
     ns = TIFFNumberOfStrips(tif);

