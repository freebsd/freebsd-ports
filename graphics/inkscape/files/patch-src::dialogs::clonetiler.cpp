--- src/dialogs/clonetiler.cpp.orig	Fri Feb 18 02:32:13 2005
+++ src/dialogs/clonetiler.cpp	Fri Feb 18 02:33:24 2005
@@ -868,7 +868,7 @@
 clonetiler_xy_changed (GtkAdjustment *adj, gpointer data)
 {
     const gchar *pref = (const gchar *) data;
-    prefs_set_int_attribute ("dialogs.clonetiler", pref, (int) round(adj->value));
+    prefs_set_int_attribute ("dialogs.clonetiler", pref, (int) rint(adj->value));
 }
 
 static void
