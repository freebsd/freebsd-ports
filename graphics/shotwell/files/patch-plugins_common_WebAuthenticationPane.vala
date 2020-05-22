--- plugins/common/WebAuthenticationPane.vala.orig	2020-05-22 13:32:52 UTC
+++ plugins/common/WebAuthenticationPane.vala
@@ -21,7 +21,7 @@ namespace Shotwell.Plugins.Common {
         public void clear() {
             try {
                 debug("Clearing the data of WebKit...");
-                this.webview.get_website_data_manager().clear.begin(WebKit.WebsiteDataTypes.ALL, (GLib.TimeSpan)0);
+                this.webview.get_website_data_manager().clear.begin(WebKit.WebsiteDataTypes.ALL, (GLib.TimeSpan)0, null);
             } catch (Error e) {
                 // Do nothing
                 message("Failed to clear data: %s", e.message);
