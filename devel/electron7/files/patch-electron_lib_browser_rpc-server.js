--- electron/lib/browser/rpc-server.js.orig	2020-03-24 05:00:48 UTC
+++ electron/lib/browser/rpc-server.js
@@ -484,7 +484,7 @@ const allowedClipboardMethods = (() => {
   switch (process.platform) {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText']);
-    case 'linux':
+    case 'linux': case 'freebsd':
       return new Set(Object.keys(clipboard));
     default:
       return new Set();
