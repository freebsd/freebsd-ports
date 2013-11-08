--- src/viewer.c.orig	2013-11-07 19:33:02.807286361 +0400
+++ src/viewer.c	2013-11-07 19:34:22.533326686 +0400
@@ -293,7 +293,7 @@
 
   if ((dv->thumb == dv->current_thumb)  &&
       ((widget->allocation.x == dv->area_x) &&
-       (widget->allocation.y == dv->area_y)    )){ return; }
+       (widget->allocation.y == dv->area_y)    )){ return 1; }
 
   dv->area_x = widget->allocation.x;
   dv->area_y = widget->allocation.y;
@@ -314,7 +314,7 @@
       filename = g_strconcat(dv->thumb->path, "/", dv->thumb->filename, NULL);
     }
   }
-  if (filename == NULL) { return; }
+  if (filename == NULL) { return 1; }
 
   viewer_read_image(dv, filename, tp);
 
@@ -555,7 +555,7 @@
   while ((thumb != NULL) && (i < (tp->viewer).adj.value)) {
     thumb = thumb->next; i++;
   }
-  if (thumb == NULL) { return; }
+  if (thumb == NULL) { return FALSE; }
 
   gtk_window_set_title(GTK_WINDOW((tp->viewer).window), 
     g_strconcat(thumb->path, "/", thumb->filename, NULL));
