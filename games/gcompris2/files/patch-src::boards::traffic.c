--- src/boards/traffic.c.orig	Wed Apr 23 10:39:07 2003
+++ src/boards/traffic.c	Wed Apr 23 10:39:32 2003
@@ -74,7 +74,7 @@
   guint num_cars;
   guint card;
   guint level;
-  car *cars[];
+  car **cars;
 };
 
 static int	 car_cb(GnomeCanvasItem *item, GdkEvent *event, car *thiscar);
