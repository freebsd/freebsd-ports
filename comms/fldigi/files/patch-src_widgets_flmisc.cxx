--- src/widgets/flmisc.cxx.orig	2013-11-19 20:07:27.667902073 -0500
+++ src/widgets/flmisc.cxx	2013-11-19 20:07:49.467902518 -0500
@@ -104,7 +104,7 @@
 	bg1r = 255 - bg1r; bg1g = 255 - bg1g; bg1b = 255 - bg1b;
 	Fl_Color adj = fl_rgb_color(bg1r, bg1g, bg1b);
 	if (fl_contrast(adj, bg2) != adj)
-		Fl::get_color((def >= 0 ? def : adj), bg1r, bg1g, bg1b);
+		Fl::get_color((def != 0 ? def : adj), bg1r, bg1g, bg1b);
 }
 
 #if !defined(__APPLE__) && !defined(__WOE32__) && USE_X
