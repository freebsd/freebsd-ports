--- /tmp/instance_owners.c	Wed Aug 18 20:23:20 2004
+++ instance_owners.c	Wed Aug 18 20:24:24 2004
@@ -16,0 +17,4 @@
+#if __FreeBSD__ < 5
+#define PRId32 "d"
+#endif
+
@@ -207 +211 @@
-    omenu = gtk_menu_new ();
+    menuitem = gtk_menu_item_new_with_label (buf);
