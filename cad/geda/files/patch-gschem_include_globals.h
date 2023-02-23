--- gschem/include/globals.h.orig	2013-08-18 17:02:48 UTC
+++ gschem/include/globals.h
@@ -27,7 +27,7 @@
 extern GList *global_window_list;
 
 /* Manager for recently used files */
-GtkRecentManager *recent_manager;
+extern GtkRecentManager *recent_manager;
 
 /* colors */
 extern GdkColor white;
