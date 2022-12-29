--- electron/lib/browser/api/app.ts.orig	2021-11-15 23:45:07 UTC
+++ electron/lib/browser/api/app.ts
@@ -67,7 +67,7 @@ if (process.platform === 'darwin') {
   app.dock!.getMenu = () => dockMenu;
 }
 
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd') {
   const patternVmRSS = /^VmRSS:\s*(\d+) kB$/m;
   const patternVmHWM = /^VmHWM:\s*(\d+) kB$/m;
 
