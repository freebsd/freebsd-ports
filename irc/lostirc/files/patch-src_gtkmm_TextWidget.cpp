--- src/gtkmm/TextWidget.cpp.orig	2017-04-05 11:26:59 UTC
+++ src/gtkmm/TextWidget.cpp
@@ -210,11 +210,11 @@ void TextWidget::insertText(const TextProperties& tp, 
     std::vector< Glib::RefPtr<Gtk::TextTag> > tags;
 
     Glib::RefPtr<Gtk::TextTag> fg = buffer->get_tag_table()->lookup(Glib::ustring("f")+crop(tp.fgnumber));
-    if (fg == 0)
+    if (!fg)
           fg = buffer->get_tag_table()->lookup("f0");
 
     Glib::RefPtr<Gtk::TextTag> bg = buffer->get_tag_table()->lookup(Glib::ustring("b")+crop(tp.bgnumber));
-    if (bg == 0)
+    if (!bg)
           bg = buffer->get_tag_table()->lookup("b0");
 
     tags.push_back(fg);
