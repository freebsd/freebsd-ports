--- electron/lib/browser/rpc-server.js.orig	2019-12-13 19:48:14 UTC
+++ electron/lib/browser/rpc-server.js
@@ -484,7 +484,7 @@ const allowedClipboardMethods = (() => {
   switch (process.platform) {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText'])
-    case 'linux':
+    case 'linux': case 'freebsd':
       return new Set(Object.keys(clipboard))
     default:
       return new Set()
