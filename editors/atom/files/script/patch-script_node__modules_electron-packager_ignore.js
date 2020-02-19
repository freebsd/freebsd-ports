--- script/node_modules/electron-packager/ignore.js.orig	2019-12-27 05:37:51 UTC
+++ script/node_modules/electron-packager/ignore.js
@@ -19,7 +19,7 @@ function generateIgnores (opts) {
     } else {
       opts.ignore = [].concat(DEFAULT_IGNORES)
     }
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd') {
       opts.ignore.push(common.baseTempDir(opts))
     }
 
