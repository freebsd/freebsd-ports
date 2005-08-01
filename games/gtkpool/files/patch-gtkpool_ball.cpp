--- gtkpool/ball.cpp.orig	Thu Aug 15 00:04:33 2002
+++ gtkpool/ball.cpp	Fri Jul 29 19:06:23 2005
@@ -53,7 +53,7 @@
 	radius = diam = 0;
 }
 
-Ball::Ball (double x, double y, int d, GdkColor *c, int cat = other, bool isq = false, bool ise = false, bool isn = false, bool isso = false, bool isst = false) : Point2D(x, y), vel(0, 0), bnc(0, 0), tvec(0, 0) {
+Ball::Ball (double x, double y, int d, GdkColor *c, int cat, bool isq, bool ise, bool isn, bool isso, bool isst) : Point2D(x, y), vel(0, 0), bnc(0, 0), tvec(0, 0) {
 	radius = (diam = d) / 2;
 	clr = c;
 	is_cue = isq; is_eight = ise; is_nine = isn;
@@ -63,7 +63,7 @@
 	ball_num = 15;
 }
 
-Ball::Ball (double x, double y, int d, int bn, GdkPixmap *pixmap, GdkBitmap *c_bmp, GdkPixmap *b_pixmap, GdkBitmap *b_clip_bmp, int cat = other, bool isq = false, bool ise = false, bool isn = false, bool isso = false, bool isst = false) : Point2D(x, y), vel(0, 0), bnc(0, 0), tvec(0, 0) {
+Ball::Ball (double x, double y, int d, int bn, GdkPixmap *pixmap, GdkBitmap *c_bmp, GdkPixmap *b_pixmap, GdkBitmap *b_clip_bmp, int cat, bool isq, bool ise, bool isn, bool isso, bool isst) : Point2D(x, y), vel(0, 0), bnc(0, 0), tvec(0, 0) {
 	radius = (diam = d) / 2;
 	clr = (GdkColor *)NULL;
 	is_cue = isq; is_eight = ise; is_nine = isn;
