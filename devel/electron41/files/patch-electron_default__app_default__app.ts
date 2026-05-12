--- electron/default_app/default_app.ts.orig	2026-05-07 20:19:20 UTC
+++ electron/default_app/default_app.ts
@@ -100,7 +100,7 @@ async function createWindow(backgroundColor?: string) 
     show: false
   };
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     options.icon = url.fileURLToPath(new URL('icon.png', import.meta.url));
   }
 
