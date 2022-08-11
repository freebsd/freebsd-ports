--- chrome/browser/resources/settings/route.ts.orig	2022-05-19 05:17:38 UTC
+++ chrome/browser/resources/settings/route.ts
@@ -185,7 +185,7 @@ function createBrowserSettingsRoutes(): SettingsRoutes
 
     r.ACCESSIBILITY = r.ADVANCED.createSection('/accessibility', 'a11y');
 
-    // <if expr="is_linux">
+    // <if expr="is_posix">
     r.CAPTIONS = r.ACCESSIBILITY.createChild('/captions');
     // </if>
 
