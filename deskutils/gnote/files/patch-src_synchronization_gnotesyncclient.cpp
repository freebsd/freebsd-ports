--- src/synchronization/gnotesyncclient.cpp.orig	2015-11-28 15:44:34 UTC
+++ src/synchronization/gnotesyncclient.cpp
@@ -54,7 +54,7 @@ namespace sync {
   {
     m_local_manifest_file_path = Glib::build_filename(IGnote::conf_dir(), LOCAL_MANIFEST_FILE_NAME);
     Glib::RefPtr<Gio::File> manifest = Gio::File::create_for_path(m_local_manifest_file_path);
-    if(manifest != 0) {
+    if(manifest) {
       m_file_watcher = manifest->monitor_file();
       m_file_watcher->signal_changed()
         .connect(sigc::mem_fun(*this, &GnoteSyncClient::on_changed));
