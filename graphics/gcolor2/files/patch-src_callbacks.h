--- src/callbacks.h.orig	2005-07-11 23:18:59 UTC
+++ src/callbacks.h
@@ -41,9 +41,9 @@
                            "\302\267 Usability / user interface enhancements\n" \
                            "\302\267 Code cleanup"
 
-GtkWidget *gcolor2;
-GtkWidget *menu;
-GdkColor   colorvalue;
+extern GtkWidget *gcolor2;
+extern GtkWidget *menu;
+extern GdkColor   colorvalue;
 
 enum
 {
