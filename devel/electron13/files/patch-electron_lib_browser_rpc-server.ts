--- electron/lib/browser/rpc-server.ts.orig	2021-10-27 21:25:28 UTC
+++ electron/lib/browser/rpc-server.ts
@@ -46,7 +46,7 @@ const allowedClipboardMethods = (() => {
   switch (process.platform) {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText']);
-    case 'linux':
+    case 'linux': case 'freebsd':
       return new Set(Object.keys(clipboard));
     default:
       return new Set();
