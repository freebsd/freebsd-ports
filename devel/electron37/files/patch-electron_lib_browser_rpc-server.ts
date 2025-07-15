--- electron/lib/browser/rpc-server.ts.orig	2025-04-04 05:26:44 UTC
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
