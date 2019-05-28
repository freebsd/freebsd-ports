--- electron/lib/browser/api/app.js.orig	2019-05-23 00:26:57 UTC
+++ electron/lib/browser/api/app.js
@@ -83,7 +83,7 @@ if (process.platform === 'darwin') {
   }
 }
 
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd') {
   app.launcher = {
     setBadgeCount: bindings.unityLauncherSetBadgeCount,
     getBadgeCount: bindings.unityLauncherGetBadgeCount,
