--- libgnomevfs/libgnomevfsmm/handle.cc.orig	Thu Jun 19 11:46:18 2003
+++ libgnomevfs/libgnomevfsmm/handle.cc	Thu Jun 19 11:46:58 2003
@@ -108,7 +108,7 @@
 Glib::RefPtr<FileInfo> Handle::get_file_info(const Glib::ustring& text_uri, FileInfoOptions options) throw(exception)
 {
   GnomeVFSFileInfo* file_info = gnome_vfs_file_info_new();
-  GnomeVFSResult result = gnome_vfs_get_file_info(text_uri.c_str(), file_info, static_cast<GnomeVFSFileInfoOptions>(options));
+  GnomeVFSResult result = gnome_vfs_get_file_info(text_uri.c_str(), file_info, GnomeVFSFileInfoOptions(options));
   handle_result(result);
   return Glib::wrap(file_info);
 }
@@ -116,7 +116,7 @@
 Glib::RefPtr<FileInfo> Handle::get_file_info(FileInfoOptions options) const throw(exception)
 {
   GnomeVFSFileInfo* file_info = gnome_vfs_file_info_new();
-  GnomeVFSResult result = gnome_vfs_get_file_info_from_handle(const_cast<GnomeVFSHandle*>(gobj()), file_info, static_cast<GnomeVFSFileInfoOptions>(options));
+  GnomeVFSResult result = gnome_vfs_get_file_info_from_handle(const_cast<GnomeVFSHandle*>(gobj()), file_info, GnomeVFSFileInfoOptions(options));
   handle_result(result);
   return Glib::wrap(file_info);
 }
