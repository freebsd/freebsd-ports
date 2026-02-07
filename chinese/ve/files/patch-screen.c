--- screen.c.orig	2014-02-21 07:38:36.000000000 +0800
+++ screen.c	2014-02-21 07:38:47.000000000 +0800
@@ -643,7 +643,7 @@
   }
 }
 
-region_scroll_up(int top, int bottom)
+void region_scroll_up(int top, int bottom)
 {
    int i;
 
