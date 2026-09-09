--- electron/lib/browser/rpc-server.ts.orig	2026-09-08 07:41:45 UTC
+++ electron/lib/browser/rpc-server.ts
@@ -38,7 +38,7 @@ const allowedClipboardMethods = (() => {
   switch (process.platform) {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText']);
-    case 'linux':
+    case 'linux': case 'freebsd':
       return new Set(Object.keys(clipboard));
     default:
       return new Set();
