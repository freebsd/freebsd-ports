--- src/wnd/fusenshieditdialog.cpp.orig	2007-06-25 08:19:21.000000000 +0200
+++ src/wnd/fusenshieditdialog.cpp	2010-04-07 17:50:35.000000000 +0200
@@ -423,10 +423,10 @@ void FusenshiEditDialog::on_fontname_cli
     fontdlg.set_title(_("Font:"));
     fontdlg.set_transient_for(*this);
     fontdlg.get_apply_button()->hide();
-    
-    fontdlg.get_font_selection()->set_font_name(m_cFontName.get_text());
+
+    fontdlg.set_font_name(m_cFontName.get_text());
     
     if (Gtk::RESPONSE_OK == fontdlg.run()) {
-        m_cFontName.set_text(fontdlg.get_font_selection()->get_font_name());
+        m_cFontName.set_text(fontdlg.get_font_name());
     }
 }
