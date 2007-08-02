--- src/gnmm.cc.orig	2007-08-02 14:24:29.000000000 +0200
+++ src/gnmm.cc	2007-08-02 14:24:52.000000000 +0200
@@ -177,7 +177,7 @@
   if (!gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(w)))
     return;
 
-  int id = (int)data;
+  intptr_t id = (intptr_t)data;
 
   if (id>=10) pref_black_level = id-10;
   else pref_white_level = id;
