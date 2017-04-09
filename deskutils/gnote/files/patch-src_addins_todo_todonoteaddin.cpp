--- src/addins/todo/todonoteaddin.cpp.orig	2015-11-28 15:44:34 UTC
+++ src/addins/todo/todonoteaddin.cpp
@@ -42,7 +42,7 @@ TodoModule::TodoModule()
 void Todo::initialize()
 {
   FOREACH(const std::string & s, s_todo_patterns) {
-    if(get_note()->get_tag_table()->lookup(s) == 0) {
+    if(!get_note()->get_tag_table()->lookup(s)) {
       Glib::RefPtr<Gtk::TextTag> tag = Gtk::TextTag::create(s);
       tag->property_foreground() = "#0080f0";
       tag->property_weight() = PANGO_WEIGHT_BOLD;
