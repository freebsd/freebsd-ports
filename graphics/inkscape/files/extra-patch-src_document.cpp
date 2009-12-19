--- src/document.cpp.orig	2009-12-19 14:57:53.000000000 -0500
+++ src/document.cpp	2009-12-19 14:59:10.000000000 -0500
@@ -183,8 +183,8 @@ SPDocument::~SPDocument() {
 
     if (oldSignalsConnected) {
         g_signal_handlers_disconnect_by_func(G_OBJECT(INKSCAPE),
-                                             reinterpret_cast<gpointer>(sp_document_reset_key),
-                                             static_cast<gpointer>(this));
+                                             (gpointer)(sp_document_reset_key),
+                                             (gpointer)(this));
     } else {
         _selection_changed_connection.disconnect();
         _desktop_activated_connection.disconnect();
