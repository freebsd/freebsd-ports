--- gd.c	Thu Apr 25 14:15:15 2002
+++ gd.c	Thu Apr 25 12:43:55 2002
@@ -2211,7 +2230,17 @@
 }
 
 void
-gdImagePolygon (gdImagePtr im, gdPointPtr p, int n, int c)
+gdImagePolygon(gdImagePtr im, gdPointPtr p, int n, int c)
+{
+	if (!n) {
+		return;
+	}
+	gdImageLine(im, p->x, p->y, p[n-1].x, p[n-1].y, c);
+	gdImageOpenPolygon(im, p, n, c);
+}	
+
+void
+gdImageOpenPolygon (gdImagePtr im, gdPointPtr p, int n, int c)
 {
   int i;
   int lx, ly;
@@ -2221,7 +2250,6 @@
     }
   lx = p->x;
   ly = p->y;
-  gdImageLine (im, lx, ly, p[n - 1].x, p[n - 1].y, c);
   for (i = 1; (i < n); i++)
     {
       p++;
@@ -2461,8 +2489,8 @@
     {
       for (x = 0; (x < sx); x++)
 	{
-	  p1 = im1->pixels[y][x];
-	  p2 = im2->pixels[y][x];
+	  p1 = im1->trueColor ? gdImageTrueColorPixel(im1, x, y) : gdImagePalettePixel(im1, x, y);
+	  p2 = im2->trueColor ? gdImageTrueColorPixel(im2, x, y) : gdImagePalettePixel(im2, x, y);
 	  if (gdImageRed (im1, p1) != gdImageRed (im2, p2))
 	    {
 	      cmpStatus |= GD_CMP_COLOR + GD_CMP_IMAGE;
