--- vid_x11.c.orig	Mon Aug 25 21:01:40 2003
+++ vid_x11.c	Mon Aug 25 21:10:09 2003
@@ -21,7 +21,8 @@
 
 #define _BSD
 
-typedef unsigned short PIXEL;
+typedef unsigned short PIXEL16;
+typedef unsigned PIXEL24;
 
 #include <ctype.h>
 #include <sys/time.h>
@@ -111,7 +112,8 @@
 void (*vid_menukeyfn)(int key);
 void VID_MenuKey (int key);
 
-static PIXEL st2d_8to16table[256];
+static PIXEL16 st2d_8to16table[256];
+static PIXEL24 st2d_8to24table[256];
 static int shiftmask_fl=0;
 static long r_shift,g_shift,b_shift;
 static unsigned long r_mask,g_mask,b_mask;
@@ -132,8 +134,42 @@
     shiftmask_fl = 1;
 }
 
-PIXEL xlib_rgb(int r,int g,int b) {
-    PIXEL p;
+PIXEL16 xlib_rgb16(int r,int g,int b) {
+    PIXEL16 p;
+
+    if (shiftmask_fl == 0) 
+		shiftmask_init();
+    p = 0;
+
+    if (r_shift > 0) {
+        p = (r << (r_shift)) &r_mask;
+    } else if(r_shift<0) {
+        p = (r >> (-r_shift)) &r_mask;
+	} else {
+		p |= (r & r_mask);
+	}
+
+    if(g_shift>0) {
+        p |= (g << (g_shift)) &g_mask;
+    } else if(g_shift<0) {
+        p |= (g >> (-g_shift)) &g_mask;
+	} else {
+		p|=(g & g_mask);
+	}
+
+    if(b_shift > 0) {
+        p |= (b << (b_shift)) &b_mask;
+    } else if (b_shift < 0) {
+        p |= (b >> (-b_shift)) &b_mask;
+	} else {
+		p|=(b & b_mask);
+	}
+
+    return p;
+}
+
+PIXEL24 xlib_rgb24(int r,int g,int b) {
+    PIXEL24 p;
 
     if (shiftmask_fl == 0) 
 		shiftmask_init();
@@ -169,20 +205,37 @@
 void st2_fixup( XImage *framebuf, int x, int y, int width, int height) {
 	int xi,yi;
 	unsigned char *src;
-	PIXEL *dest;
+	PIXEL16 *dest;
 
 	if(x < 0 || y < 0)
 		return;
 
 	for (yi = y; yi < y + height; yi++) {
 		src = &framebuf->data [yi * framebuf->bytes_per_line];
-		dest = (PIXEL*)src;
+		dest = (PIXEL16 *)src;
 		for(xi = (x + width - 1); xi >= x; xi--) {
 			dest[xi] = st2d_8to16table[src[xi]];
 		}
 	}
 }
 
+void st3_fixup( XImage *framebuf, int x, int y, int width, int height) {
+	int xi,yi;
+	unsigned char *src;
+	PIXEL24 *dest;
+
+	if(x < 0 || y < 0)
+		return;
+
+	for (yi = y; yi < y + height; yi++) {
+		src = &framebuf->data [yi * framebuf->bytes_per_line];
+		dest = (PIXEL24 *)src;
+		for(xi = (x + width - 1); xi >= x; xi--) {
+			dest[xi] = st2d_8to24table[src[xi]];
+		}
+	}
+}
+
 // ========================================================================
 // Tragic death handler
 // ========================================================================
@@ -564,8 +617,10 @@
 	int i;
 	XColor colors[256];
 
-	for (i = 0; i < 256; i++)
-		st2d_8to16table[i]= xlib_rgb(palette[i * 3], palette[i * 3 + 1], palette[i * 3 + 2]);
+	for (i = 0; i < 256; i++) {
+		st2d_8to24table[i]= xlib_rgb24(palette[i * 3], palette[i * 3 + 1], palette[i * 3 + 2]);
+		st2d_8to16table[i]= xlib_rgb16(palette[i * 3], palette[i * 3 + 1], palette[i * 3 + 2]);
+	}
 
 	if (x_visinfo->class == PseudoColor && x_visinfo->depth == 8) {
 		if (palette != current_palette)
@@ -821,7 +876,9 @@
 
 	if (doShm) {
 		while (rects){
-			if (x_visinfo->depth != 8)
+			if (x_visinfo->depth == 24)
+				st3_fixup( x_framebuffer[current_framebuffer], rects->x, rects->y, rects->width, rects->height);
+			else if (x_visinfo->depth == 16)
 				st2_fixup( x_framebuffer[current_framebuffer], rects->x, rects->y, rects->width, rects->height);
 			if (!XShmPutImage(x_disp, x_win, x_gc,
 				x_framebuffer[current_framebuffer], rects->x, rects->y, rects->x, rects->y, rects->width, rects->height, True))
