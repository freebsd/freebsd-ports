--- electron/lib/browser/rpc-server.js.orig	2020-08-25 14:33:56 UTC
+++ electron/lib/browser/rpc-server.js
@@ -491,7 +491,7 @@ const allowedClipboardMethods = (() => {
   switch (process.platform) {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText']);
-    case 'linux':
+    case 'linux': case 'freebsd':
       return new Set(Object.keys(clipboard));
     default:
       return new Set();
