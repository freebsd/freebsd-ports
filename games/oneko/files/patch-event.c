--- event.c.orig	2014-06-05 16:17:55.096065622 +0200
+++ event.c	2014-06-05 16:21:05.995052448 +0200
@@ -106,6 +106,7 @@
 		   0, 0, toy->width, toy->height);
 }
 
+void
 NekoChangeVisibility(window)
 Window window;
 {
