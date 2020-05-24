--- electron/default_app/default_app.js.orig	2019-12-19 06:10:58 UTC
+++ electron/default_app/default_app.js
@@ -27,7 +27,7 @@ exports.load = async (appUrl) => {
     show: false
   }
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     options.icon = path.join(__dirname, 'icon.png')
   }
 
