--- Animated_Icon.cc.orig	Wed Sep  3 19:04:06 2003
+++ Animated_Icon.cc	Wed Sep  3 19:04:14 2003
@@ -1,7 +1,7 @@
 #include <FL/Fl.H>
 #include <FL/Animated_Icon.h>
 
-Animated_Icon::Animated_Icon(int x, int y, int w, int h, const char *l = 0) :
+Animated_Icon::Animated_Icon(int x, int y, int w, int h, const char *l) :
 	Fl_Box(x, y, w, h, l)
 {
 	first = current = 0;
