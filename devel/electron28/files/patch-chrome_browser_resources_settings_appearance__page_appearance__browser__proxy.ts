--- chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.ts.orig	2023-08-10 01:48:36 UTC
+++ chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.ts
@@ -18,7 +18,7 @@ export interface AppearanceBrowserProxy {
 
   useDefaultTheme(): void;
 
-  // <if expr="is_linux">
+  // <if expr="is_posix">
   useGtkTheme(): void;
   useQtTheme(): void;
   // </if>
@@ -48,7 +48,7 @@ export class AppearanceBrowserProxyImpl implements App
     chrome.send('useDefaultTheme');
   }
 
-  // <if expr="is_linux">
+  // <if expr="is_posix">
   useGtkTheme() {
     chrome.send('useGtkTheme');
   }
