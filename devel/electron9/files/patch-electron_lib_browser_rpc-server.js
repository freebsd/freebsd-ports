--- electron/lib/browser/rpc-server.js.orig	2020-06-02 18:14:21 UTC
+++ electron/lib/browser/rpc-server.js
@@ -44,7 +44,7 @@ const allowedClipboardMethods = (() => {
   switch (process.platform) {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText']);
-    case 'linux':
+    case 'linux': case 'freebsd':
       return new Set(Object.keys(clipboard));
     default:
       return new Set();
