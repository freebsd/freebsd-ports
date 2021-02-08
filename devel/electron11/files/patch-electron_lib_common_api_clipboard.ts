--- electron/lib/common/api/clipboard.ts.orig	2021-01-25 12:16:04 UTC
+++ electron/lib/common/api/clipboard.ts
@@ -12,7 +12,7 @@ if (process.type === 'renderer') {
     };
   };
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     // On Linux we could not access clipboard in renderer process.
     for (const method of Object.keys(clipboard) as (keyof Electron.Clipboard)[]) {
       clipboard[method] = makeRemoteMethod(method);
