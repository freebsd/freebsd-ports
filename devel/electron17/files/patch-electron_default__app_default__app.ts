--- electron/default_app/default_app.ts.orig	2021-11-08 18:41:28 UTC
+++ electron/default_app/default_app.ts
@@ -58,7 +58,7 @@ async function createWindow (backgroundColor?: string)
     show: false
   };
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     options.icon = path.join(__dirname, 'icon.png');
   }
 
