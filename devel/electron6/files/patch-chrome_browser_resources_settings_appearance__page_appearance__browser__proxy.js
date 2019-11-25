--- chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.js.orig	2019-09-10 11:13:42 UTC
+++ chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.js
@@ -35,7 +35,7 @@ cr.define('settings', function() {
 
     useDefaultTheme() {}
 
-    // <if expr="is_linux and not chromeos">
+    // <if expr="is_bsd and not chromeos">
     useSystemTheme() {}
 
     // </if>
@@ -93,7 +93,7 @@ cr.define('settings', function() {
       chrome.send('useDefaultTheme');
     }
 
-    // <if expr="is_linux and not chromeos">
+    // <if expr="is_bsd and not chromeos">
     /** @override */
     useSystemTheme() {
       chrome.send('useSystemTheme');
