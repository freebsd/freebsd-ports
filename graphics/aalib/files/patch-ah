--- src/aarender.c.orig	Thu Apr 26 23:37:31 2001
+++ src/aarender.c	Sat Mar  2 23:02:04 2002
@@ -27,11 +27,11 @@
     return (p);
 }
 #define MYLONG_MAX 0xffffffffU     /*this is enought for me. */
-#define myrand() (state = ((state * 1103515245) + 12345) & MYLONG_MAX)
+#define myrand() (random() & MYLONG_MAX)
 
 void aa_renderpalette(aa_context * c, __AA_CONST aa_palette palette, __AA_CONST aa_renderparams * p, int x1, int y1, int x2, int y2)
 {
-    static int state;
+    static int rand_init = 0;
     int x, y;
     int val;
     int wi = c->imgwidth;
@@ -47,6 +47,11 @@
     int randomval = p->randomval;
     int dither = p->dither;
     aa_palette table;
+
+    if (!rand_init) {
+       srandomdev();
+       rand_init = 1;
+    }
     if (x2 < 0 || y2 < 0 || x1 > aa_scrwidth(c) || y1 > aa_scrheight(c))
 	return;
     if (x2 >= aa_scrwidth(c))
