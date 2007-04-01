--- splash/Splash.cc.orig	Tue Feb 27 14:05:52 2007
+++ splash/Splash.cc
@@ -2826,7 +2826,10 @@
 void Splash::compositeBackground(SplashColorPtr color) {
   SplashColorPtr p;
   Guchar *q;
-  Guchar alpha, alpha1, c, color0, color1, color2, color3;
+  Guchar alpha, alpha1, c, color0, color1, color2;
+#if SPLASH_CMYK
+  Guchar color3;
+#endif
   int x, y, mask;
 
   switch (bitmap->mode) {
