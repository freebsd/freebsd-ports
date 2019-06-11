--- electron/lib/browser/api/app.js.orig	2019-05-30 22:14:00 UTC
+++ electron/lib/browser/api/app.js
@@ -71,7 +71,7 @@ if (process.platform === 'darwin') {
   }
 }
 
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd') {
   app.launcher = {
     setBadgeCount: bindings.unityLauncherSetBadgeCount,
     getBadgeCount: bindings.unityLauncherGetBadgeCount,
