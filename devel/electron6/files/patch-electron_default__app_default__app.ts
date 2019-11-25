--- electron/default_app/default_app.ts.orig	2019-09-11 17:30:11 UTC
+++ electron/default_app/default_app.ts
@@ -63,7 +63,7 @@ async function createWindow () {
     show: false
   }
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     options.icon = path.join(__dirname, 'icon.png')
   }
 
