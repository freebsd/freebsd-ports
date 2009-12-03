
$FreeBSD$

--- src/importer/flickr-chooser-dialog.cpp.orig
+++ src/importer/flickr-chooser-dialog.cpp
@@ -80,6 +80,8 @@
         virtual
         ~FlickrDialogModelColumnRecord() throw();
 
+        FlickrDialogModelColumnRecord(const FlickrDialogModelColumnRecord&) throw();
+
         const Gtk::TreeModelColumn<bool> &
         get_column_selected() const throw();
 
