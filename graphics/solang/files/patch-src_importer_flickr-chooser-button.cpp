
$FreeBSD$

--- src/importer/flickr-chooser-button.cpp.orig
+++ src/importer/flickr-chooser-button.cpp
@@ -53,6 +53,8 @@
         virtual
         ~FlickrButtonModelColumnRecord() throw();
 
+        FlickrButtonModelColumnRecord(const FlickrButtonModelColumnRecord&) throw();
+
         const Gtk::TreeModelColumn<PixbufPtr> &
         get_column_pixbuf() const throw();
 
