--- src/dialogs/gcs-about-window.cc.orig
+++ src/dialogs/gcs-about-window.cc
@@ -48,9 +48,9 @@
 
 #ifdef HAVE_GNOME
             set_url_hook(sigc::mem_fun(*this, &AboutWindow::on_link_clicked));
+#endif // HAVE_GNOME
             set_website(PACKAGE_WEBSITE);
             set_website_label(_("Project Website"));
-#endif // HAVE_GNOME
 
             Glib::ustring version(PACKAGE_VERSION);
             set_version(version);
@@ -111,14 +111,14 @@
         }
 
 
+#ifdef HAVE_GNOME
         void
         AboutWindow::on_link_clicked(Gtk::AboutDialog& dialog,
                 const Glib::ustring& link)
         {
-#ifdef HAVE_GNOME
             gnome_url_show(link.c_str(), 0);
-#endif // HAVE_GNOME
         }
+#endif // HAVE_GNOME
 
         void
         AboutWindow::on_response(int response_id)
