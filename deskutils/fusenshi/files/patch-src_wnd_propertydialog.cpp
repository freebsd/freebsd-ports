--- src/wnd/propertydialog.cpp.orig	2010-04-07 17:27:39.000000000 +0200
+++ src/wnd/propertydialog.cpp	2010-04-07 17:28:12.000000000 +0200
@@ -471,10 +471,10 @@ void PropertyDialog::on_fontname_clicked
     fontdlg.set_transient_for(*this);
     fontdlg.get_apply_button()->hide();
     
-    fontdlg.get_font_selection()->set_font_name(m_cFontName.get_text());
+    fontdlg.set_font_name(m_cFontName.get_text());
     
     if (Gtk::RESPONSE_OK == fontdlg.run()) {
-        m_cFontName.set_text(fontdlg.get_font_selection()->get_font_name());
+        m_cFontName.set_text(fontdlg.get_font_name());
     }
 }
 
