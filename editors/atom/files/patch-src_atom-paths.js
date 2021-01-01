--- src/atom-paths.js.orig	2019-12-13 19:07:42 UTC
+++ src/atom-paths.js
@@ -19,7 +19,7 @@ const getAppDirectory = () => {
         0,
         process.execPath.indexOf('.app') + 4
       );
-    case 'linux':
+    case 'linux': case 'freebsd':
     case 'win32':
       return path.join(process.execPath, '..');
   }
