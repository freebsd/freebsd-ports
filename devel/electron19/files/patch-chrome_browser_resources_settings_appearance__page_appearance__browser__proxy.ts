--- chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.ts.orig	2022-05-25 04:00:49 UTC
+++ chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.ts
@@ -16,7 +16,7 @@ export interface AppearanceBrowserProxy {
 
   useDefaultTheme(): void;
 
-  // <if expr="is_linux and not chromeos_ash">
+  // <if expr="is_bsd and not chromeos_ash">
   useSystemTheme(): void;
   // </if>
 
@@ -44,7 +44,7 @@ export class AppearanceBrowserProxyImpl implements App
     chrome.send('useDefaultTheme');
   }
 
-  // <if expr="is_linux and not chromeos_ash">
+  // <if expr="is_bsd and not chromeos_ash">
   useSystemTheme() {
     chrome.send('useSystemTheme');
   }
