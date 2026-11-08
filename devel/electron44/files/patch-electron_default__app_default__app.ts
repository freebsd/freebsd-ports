--- electron/default_app/default_app.ts.orig	2026-09-15 22:52:01 UTC
+++ electron/default_app/default_app.ts
@@ -94,7 +94,7 @@ async function createWindow(backgroundColor?: string) 
     show: false
   };
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     options.icon = url.fileURLToPath(new URL('icon.png', import.meta.url));
   }
 
