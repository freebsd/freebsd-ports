--- gtkpool/ball.h.orig	2002-07-29 10:02:15.000000000 +0900
+++ gtkpool/ball.h	2011-08-19 04:36:31.000000000 +0900
@@ -80,8 +80,8 @@
 	GdkColor *clr;
 
 	Ball(void);
-	Ball (double x, double y, int d, GdkColor *c, int cat, bool isq = false, bool ise = false, bool isn = false, bool isso = false, bool isst = false);
-	Ball (double x, double y, int d, int bn, GdkPixmap *pixmap, GdkBitmap *c_bmp, GdkPixmap *b_pixmap, GdkBitmap *b_clip_bmp, int cat, bool isq = false, bool ise = false, bool isn = false, bool isso = false, bool isst = false);
+	Ball (double x, double y, int d, GdkColor *c, int cat = other, bool isq = false, bool ise = false, bool isn = false, bool isso = false, bool isst = false);
+	Ball (double x, double y, int d, int bn, GdkPixmap *pixmap, GdkBitmap *c_bmp, GdkPixmap *b_pixmap, GdkBitmap *b_clip_bmp, int cat = other, bool isq = false, bool ise = false, bool isn = false, bool isso = false, bool isst = false);
 	bool moving ();
 	void decel (double val);
 	double pathIntercept (Ball b);
