--- electron/lib/browser/rpc-server.ts.orig	2021-01-25 12:26:10 UTC
+++ electron/lib/browser/rpc-server.ts
@@ -42,7 +42,7 @@ const allowedClipboardMethods = (() => {
   switch (process.platform) {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText']);
-    case 'linux':
+    case 'linux': case 'freebsd':
       return new Set(Object.keys(clipboard));
     default:
       return new Set();
