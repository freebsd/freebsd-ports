--- electron/default_app/default_app.ts.orig	2024-10-09 13:53:06 UTC
+++ electron/default_app/default_app.ts
@@ -61,7 +61,7 @@ async function createWindow (backgroundColor?: string)
     show: false
   };
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     options.icon = url.fileURLToPath(new URL('icon.png', import.meta.url));
   }
 
