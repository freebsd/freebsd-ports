--- electron/default_app/default_app.ts.orig	2023-12-04 18:19:02 UTC
+++ electron/default_app/default_app.ts
@@ -60,7 +60,7 @@ async function createWindow (backgroundColor?: string)
     show: false
   };
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     options.icon = url.fileURLToPath(new URL('icon.png', import.meta.url));
   }
 
