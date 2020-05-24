--- electron/lib/browser/api/app.js.orig	2019-06-04 19:13:27 UTC
+++ electron/lib/browser/api/app.js
@@ -84,7 +84,7 @@ if (process.platform === 'darwin') {
   }
 }
 
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd') {
   app.launcher = {
     setBadgeCount: bindings.unityLauncherSetBadgeCount,
     getBadgeCount: bindings.unityLauncherGetBadgeCount,
