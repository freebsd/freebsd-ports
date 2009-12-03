
$FreeBSD$

--- src/renderer/browser-model-column-record.h.orig
+++ src/renderer/browser-model-column-record.h
@@ -36,6 +36,8 @@
         virtual
         ~BrowserModelColumnRecord() throw();
 
+        BrowserModelColumnRecord(const BrowserModelColumnRecord&) throw();
+
         const Gtk::TreeModelColumn<guint> &
         get_column_serial() const throw();
 
