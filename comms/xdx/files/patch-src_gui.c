--- src/gui.c.orig	2020-08-23 16:44:09 UTC
+++ src/gui.c
@@ -41,6 +41,7 @@
 #include "text.h"
 
 extern preferencestype preferences;
+guitype *gui;
 
 static void on_highcheck_toggled (GtkToggleButton *togglebutton, gpointer user_data);
 static void on_soundcheck_toggled (GtkToggleButton *togglebutton, gpointer user_data);
