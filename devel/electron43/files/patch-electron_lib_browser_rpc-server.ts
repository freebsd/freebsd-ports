--- electron/lib/browser/rpc-server.ts.orig	2026-09-18 15:42:59 UTC
+++ electron/lib/browser/rpc-server.ts
@@ -36,7 +36,7 @@ const allowedClipboardMethods = (() => {
   switch (process.platform) {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText']);
-    case 'linux':
+    case 'linux': case 'freebsd':
       return new Set(Object.keys(clipboard));
     default:
       return new Set();
