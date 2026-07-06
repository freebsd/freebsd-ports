--- electron/lib/browser/rpc-server.ts.orig	2026-06-03 19:18:10 UTC
+++ electron/lib/browser/rpc-server.ts
@@ -33,7 +33,7 @@ const allowedClipboardMethods = (() => {
   switch (process.platform) {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText']);
-    case 'linux':
+    case 'linux': case 'freebsd':
       return new Set(Object.keys(clipboard));
     default:
       return new Set();
