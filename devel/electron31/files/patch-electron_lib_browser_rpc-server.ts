--- electron/lib/browser/rpc-server.ts.orig	2024-10-09 13:53:12 UTC
+++ electron/lib/browser/rpc-server.ts
@@ -28,7 +28,7 @@ const allowedClipboardMethods = (() => {
   switch (process.platform) {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText']);
-    case 'linux':
+    case 'linux': case 'freebsd':
       return new Set(Object.keys(clipboard));
     default:
       return new Set();
