--- chrome/browser/resources/settings/route.ts.orig	2022-05-11 07:16:48 UTC
+++ chrome/browser/resources/settings/route.ts
@@ -177,7 +177,7 @@ function createBrowserSettingsRoutes(): SettingsRoutes
 
     r.ACCESSIBILITY = r.ADVANCED.createSection('/accessibility', 'a11y');
 
-    // <if expr="is_linux">
+    // <if expr="is_posix">
     r.CAPTIONS = r.ACCESSIBILITY.createChild('/captions');
     // </if>
 
