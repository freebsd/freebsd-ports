--- electron/default_app/default_app.ts.orig	2020-03-24 05:00:48 UTC
+++ electron/default_app/default_app.ts
@@ -59,7 +59,7 @@ async function createWindow () {
     show: false
   };
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     options.icon = path.join(__dirname, 'icon.png');
   }
 
