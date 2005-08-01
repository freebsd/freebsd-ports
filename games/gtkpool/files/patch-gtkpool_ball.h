--- gtkpool/ball.h.orig	Mon Jul 29 08:02:15 2002
+++ gtkpool/ball.h	Fri Jul 29 18:58:49 2005
@@ -80,7 +80,7 @@
 	GdkColor *clr;
 
 	Ball(void);
-	Ball (double x, double y, int d, GdkColor *c, int cat, bool isq = false, bool ise = false, bool isn = false, bool isso = false, bool isst = false);
+	Ball (double x, double y, int d, GdkColor *c, int cat = other, bool isq = false, bool ise = false, bool isn = false, bool isso = false, bool isst = false);
 	Ball (double x, double y, int d, int bn, GdkPixmap *pixmap, GdkBitmap *c_bmp, GdkPixmap *b_pixmap, GdkBitmap *b_clip_bmp, int cat, bool isq = false, bool ise = false, bool isn = false, bool isso = false, bool isst = false);
 	bool moving ();
 	void decel (double val);
