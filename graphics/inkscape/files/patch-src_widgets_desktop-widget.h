--- src/widgets/desktop-widget.h.orig	2013-10-17 12:28:59.000000000 +0200
+++ src/widgets/desktop-widget.h	2013-10-17 12:38:00.000000000 +0200
@@ -239,7 +239,7 @@
 private:
     GtkWidget *tool_toolbox;
     GtkWidget *aux_toolbox;
-    GtkWidget *commands_toolbox,;
+    GtkWidget *commands_toolbox;
     GtkWidget *snap_toolbox;
 
     static void init(SPDesktopWidget *widget);
