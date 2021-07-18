--- electron/lib/common/api/clipboard.ts.orig	2021-04-20 23:32:33 UTC
+++ electron/lib/common/api/clipboard.ts
@@ -14,7 +14,7 @@ if (process.type === 'renderer') {
     };
   };
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     // On Linux we could not access clipboard in renderer process.
     for (const method of Object.keys(clipboard) as (keyof Electron.Clipboard)[]) {
       clipboard[method] = makeRemoteMethod(method);
