--- electron/lib/common/api/clipboard.ts.orig	2021-12-03 01:46:05 UTC
+++ electron/lib/common/api/clipboard.ts
@@ -11,7 +11,7 @@ if (process.type === 'renderer') {
     return (...args: any[]) => ipcRendererUtils.invokeSync(IPC_MESSAGES.BROWSER_CLIPBOARD_SYNC, method, ...args);
   };
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     // On Linux we could not access clipboard in renderer process.
     for (const method of Object.keys(clipboard) as (keyof Electron.Clipboard)[]) {
       clipboard[method] = makeRemoteMethod(method);
