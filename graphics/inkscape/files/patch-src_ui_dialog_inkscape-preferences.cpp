--- src/ui/dialog/inkscape-preferences.cpp.orig	2013-10-17 12:28:59.000000000 +0200
+++ src/ui/dialog/inkscape-preferences.cpp	2013-10-17 13:14:45.000000000 +0200
@@ -420,6 +420,7 @@
     this->AddPage(_page_selector, _("Selector"), iter_tools, PREFS_PAGE_TOOLS_SELECTOR);
 
     AddSelcueCheckbox(_page_selector, "/tools/select", false);
+    AddGradientCheckbox(_page_selector, "/tools/select", false);
     _page_selector.add_group_header( _("When transforming, show:"));
     _t_sel_trans_obj.init ( _("Objects"), "/tools/select/show", "content", true, 0);
     _page_selector.add_line( true, "", _t_sel_trans_obj, "",
@@ -1239,8 +1240,8 @@
         gchar** splits = g_strsplit(choices.data(), ",", 0);
         gint numIems = g_strv_length(splits);
 
-        Glib::ustring labels[numIems];
-        int values[numIems];
+        Glib::ustring *labels = new Glib::ustring[numIems];
+        int *values = new int[numIems];
         for ( gint i = 0; i < numIems; i++) {
             values[i] = i;
             labels[i] = splits[i];
@@ -1249,6 +1250,8 @@
         _page_bitmaps.add_line( false, _("Bitmap editor:"), _misc_bitmap_editor, "", "", false);
 
         g_strfreev(splits);
+        delete[] values;
+        delete[] labels;
     }
 
     _bitmap_copy_res.init("/options/createbitmap/resolution", 1.0, 6000.0, 1.0, 1.0, PX_PER_IN, true, false);
