--- libgnomevfs/libgnomevfsmm/directory-handle.cc.orig	Thu Jun 19 11:43:18 2003
+++ libgnomevfs/libgnomevfsmm/directory-handle.cc	Thu Jun 19 11:45:32 2003
@@ -97,13 +97,13 @@
 
 void DirectoryHandle::open(const Glib::ustring& text_uri, FileInfoOptions options) throw(exception)
 {
-  GnomeVFSResult result = gnome_vfs_directory_open(&gobj_, text_uri.c_str(), static_cast<GnomeVFSFileInfoOptions>(options) );
+  GnomeVFSResult result = gnome_vfs_directory_open(&gobj_, text_uri.c_str(), GnomeVFSFileInfoOptions(options) );
   handle_result(result);
 }
 
 void DirectoryHandle::open(const Glib::RefPtr<const Uri>& uri, FileInfoOptions options) throw(exception)
 {
-  GnomeVFSResult result = gnome_vfs_directory_open_from_uri(&gobj_, const_cast<GnomeVFSURI*>(uri->gobj()), static_cast<GnomeVFSFileInfoOptions>(options) );
+  GnomeVFSResult result = gnome_vfs_directory_open_from_uri(&gobj_, const_cast<GnomeVFSURI*>(uri->gobj()), GnomeVFSFileInfoOptions(options) );
   handle_result(result);
 }
 
@@ -132,14 +132,14 @@
 void DirectoryHandle::visit(const Glib::ustring& uri, FileInfoOptions info_options, DirectoryVisitOptions visit_options, const SlotVisit& slot) throw(exception)
 {
   SignalProxy_Visit proxy(slot);
-  GnomeVFSResult result = gnome_vfs_directory_visit(uri.c_str(), static_cast<GnomeVFSFileInfoOptions>(info_options), static_cast<GnomeVFSDirectoryVisitOptions>(visit_options), &SignalProxy_Visit::c_callback, &proxy);
+  GnomeVFSResult result = gnome_vfs_directory_visit(uri.c_str(), GnomeVFSFileInfoOptions(info_options), GnomeVFSDirectoryVisitOptions(visit_options), &SignalProxy_Visit::c_callback, &proxy);
   handle_result(result);
 }
 
 void DirectoryHandle::visit(const Glib::RefPtr<const Uri>& uri, FileInfoOptions info_options, DirectoryVisitOptions visit_options, const SlotVisit& slot) throw(exception)
 {
   SignalProxy_Visit proxy(slot);
-  GnomeVFSResult result = gnome_vfs_directory_visit_uri(const_cast<GnomeVFSURI*>(uri->gobj()), static_cast<GnomeVFSFileInfoOptions>(info_options), static_cast<GnomeVFSDirectoryVisitOptions>(visit_options), &SignalProxy_Visit::c_callback, &proxy);
+  GnomeVFSResult result = gnome_vfs_directory_visit_uri(const_cast<GnomeVFSURI*>(uri->gobj()), GnomeVFSFileInfoOptions(info_options), GnomeVFSDirectoryVisitOptions(visit_options), &SignalProxy_Visit::c_callback, &proxy);
   handle_result(result);
 }
  
