--- electron/lib/browser/api/app.ts.orig	2026-05-07 20:19:20 UTC
+++ electron/lib/browser/api/app.ts
@@ -71,7 +71,7 @@ if (process.platform === 'darwin') {
   app.dock!.getMenu = () => dockMenu;
 }
 
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd') {
   const patternVmRSS = /^VmRSS:\s*(\d+) kB$/m;
   const patternVmHWM = /^VmHWM:\s*(\d+) kB$/m;
 
