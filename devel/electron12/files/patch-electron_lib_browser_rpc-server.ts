--- electron/lib/browser/rpc-server.ts.orig	2021-04-20 23:32:33 UTC
+++ electron/lib/browser/rpc-server.ts
@@ -43,7 +43,7 @@ const allowedClipboardMethods = (() => {
   switch (process.platform) {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText']);
-    case 'linux':
+    case 'linux': case 'freebsd':
       return new Set(Object.keys(clipboard));
     default:
       return new Set();
