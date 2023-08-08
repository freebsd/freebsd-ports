--- electron/lib/browser/rpc-server.ts.orig	2022-05-11 15:32:29 UTC
+++ electron/lib/browser/rpc-server.ts
@@ -26,7 +26,7 @@ const allowedClipboardMethods = (() => {
   switch (process.platform) {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText']);
-    case 'linux':
+    case 'linux': case 'freebsd':
       return new Set(Object.keys(clipboard));
     default:
       return new Set();
