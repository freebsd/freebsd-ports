--- gd.c.orig	Sat Mar 29 17:25:42 2003
+++ gd.c	Wed May 14 16:46:34 2003
@@ -2696,6 +2696,16 @@
 void
 gdImagePolygon (gdImagePtr im, gdPointPtr p, int n, int c)
 {
+	if (!n) {
+		return;
+	}
+	gdImageLine(im, p->x, p->y, p[n-1].x, p[n-1].y, c);
+	gdImageOpenPolygon(im, p, n, c);
+}	
+
+void
+gdImageOpenPolygon (gdImagePtr im, gdPointPtr p, int n, int c)
+{
   int i;
   int lx, ly;
   if (!n)
@@ -2710,7 +2720,6 @@
 
   lx = p->x;
   ly = p->y;
-  gdImageLine (im, lx, ly, p[n - 1].x, p[n - 1].y, c);
   for (i = 1; (i < n); i++)
     {
       p++;
