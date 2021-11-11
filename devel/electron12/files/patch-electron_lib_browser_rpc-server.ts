--- electron/lib/browser/rpc-server.ts.orig	2021-10-11 17:12:26 UTC
+++ electron/lib/browser/rpc-server.ts
@@ -47,7 +47,7 @@ const allowedClipboardMethods = (() => {
   switch (process.platform) {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText']);
-    case 'linux':
+    case 'linux': case 'freebsd':
       return new Set(Object.keys(clipboard));
     default:
       return new Set();
