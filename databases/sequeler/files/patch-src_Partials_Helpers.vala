GRANITE_STYLE_CLASS_ACCENT is not available in granite 0.5

--- src/Partials/Helpers.vala.orig	2018-12-30 06:28:03 UTC
+++ src/Partials/Helpers.vala
@@ -98,7 +98,6 @@ namespace Sequeler.Partials { 
 
     class UrlButton : Gtk.Button {
         public UrlButton (string label, string uri, string icon_name) {
-            get_style_context ().add_class (Granite.STYLE_CLASS_ACCENT);
             get_style_context ().add_class (Gtk.STYLE_CLASS_FLAT);
             tooltip_text = uri;
 
