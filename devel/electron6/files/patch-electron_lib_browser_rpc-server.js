--- electron/lib/browser/rpc-server.js.orig	2019-12-17 00:40:10 UTC
+++ electron/lib/browser/rpc-server.js
@@ -481,7 +481,7 @@ const allowedClipboardMethods = (() => {
   switch (process.platform) {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText'])
-    case 'linux':
+    case 'linux': case 'freebsd':
       return new Set(Object.keys(clipboard))
     default:
       return new Set()
