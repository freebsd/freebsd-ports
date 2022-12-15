--- chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.ts.orig	2022-07-22 17:30:31 UTC
+++ chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.ts
@@ -16,7 +16,7 @@ export interface AppearanceBrowserProxy {
 
   useDefaultTheme(): void;
 
-  // <if expr="is_linux">
+  // <if expr="is_bsd">
   useSystemTheme(): void;
   // </if>
 
@@ -44,7 +44,7 @@ export class AppearanceBrowserProxyImpl implements App
     chrome.send('useDefaultTheme');
   }
 
-  // <if expr="is_linux">
+  // <if expr="is_bsd">
   useSystemTheme() {
     chrome.send('useSystemTheme');
   }
