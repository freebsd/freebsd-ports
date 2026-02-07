--- electron/lib/browser/rpc-server.ts.orig	2025-09-02 20:56:04 UTC
+++ electron/lib/browser/rpc-server.ts
@@ -34,7 +34,7 @@ const allowedClipboardMethods = (() => {
   switch (process.platform) {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText']);
-    case 'linux':
+    case 'linux': case 'freebsd':
       return new Set(Object.keys(clipboard));
     default:
       return new Set();
