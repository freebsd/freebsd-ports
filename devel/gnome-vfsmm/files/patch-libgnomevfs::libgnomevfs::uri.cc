--- libgnomevfs/libgnomevfsmm/uri.cc.orig	Thu Jun 19 11:25:08 2003
+++ libgnomevfs/libgnomevfsmm/uri.cc	Thu Jun 19 11:44:28 2003
@@ -66,7 +66,7 @@
 Glib::RefPtr<FileInfo> Uri::get_file_info(FileInfoOptions options) const throw(exception)
 {
   GnomeVFSFileInfo* file_info = gnome_vfs_file_info_new();
-  GnomeVFSResult result = gnome_vfs_get_file_info_uri(const_cast<GnomeVFSURI*>(gobj()), file_info, static_cast<GnomeVFSFileInfoOptions>(options));
+  GnomeVFSResult result = gnome_vfs_get_file_info_uri(const_cast<GnomeVFSURI*>(gobj()), file_info, GnomeVFSFileInfoOptions(options));
   handle_result(result);
   return Glib::wrap(file_info);
 }
