$FreeBSD$

--- instance_owners.c.orig	Fri Jun 25 02:20:42 2004
+++ instance_owners.c	Fri Jun 25 02:28:35 2004
@@ -16,0 +17,4 @@
+#if __FreeBSD__ < 5
+#define PRId32 "d"
+#endif
+
@@ -205,0 +210 @@
+    GtkWidget* menuitem;
@@ -207 +212 @@
-    GtkWidget* menuitem = gtk_menu_item_new_with_label (buf);
+    menuitem = gtk_menu_item_new_with_label (buf);
