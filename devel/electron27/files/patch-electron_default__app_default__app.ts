--- electron/default_app/default_app.ts.orig	2022-05-18 15:31:32 UTC
+++ electron/default_app/default_app.ts
@@ -59,7 +59,7 @@ async function createWindow (backgroundColor?: string)
     show: false
   };
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     options.icon = path.join(__dirname, 'icon.png');
   }
 
