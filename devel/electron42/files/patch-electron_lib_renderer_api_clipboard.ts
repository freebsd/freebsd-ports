--- electron/lib/renderer/api/clipboard.ts.orig	2026-01-15 18:39:20 UTC
+++ electron/lib/renderer/api/clipboard.ts
@@ -27,7 +27,7 @@ const makeRemoteMethod = function (method: keyof Elect
   };
 };
 
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd') {
   // On Linux we could not access clipboard in renderer process.
   for (const method of Object.keys(originalClipboard) as (keyof Electron.Clipboard)[]) {
     clipboard[method] = makeRemoteMethod(method);
