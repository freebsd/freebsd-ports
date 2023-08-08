--- triceratops_gui.cpp.orig	2023-06-04 18:06:02 UTC
+++ triceratops_gui.cpp
@@ -312,7 +312,7 @@ static GtkWidget* make_gui(triceratopsGUI *self) {
 }
 
 
-static LV2UI_Handle instantiate(const struct _LV2UI_Descriptor * descriptor,
+static LV2UI_Handle instantiate(const struct LV2UI_Descriptor * descriptor,
                 const char * plugin_uri,
                 const char * bundle_path,
                 LV2UI_Write_Function write_function,
