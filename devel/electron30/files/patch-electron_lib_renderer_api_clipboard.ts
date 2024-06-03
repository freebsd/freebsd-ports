--- electron/lib/renderer/api/clipboard.ts.orig	2023-08-14 18:19:06 UTC
+++ electron/lib/renderer/api/clipboard.ts
@@ -7,7 +7,7 @@ const makeRemoteMethod = function (method: keyof Elect
   return (...args: any[]) => ipcRendererUtils.invokeSync(IPC_MESSAGES.BROWSER_CLIPBOARD_SYNC, method, ...args);
 };
 
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd') {
   // On Linux we could not access clipboard in renderer process.
   for (const method of Object.keys(clipboard) as (keyof Electron.Clipboard)[]) {
     clipboard[method] = makeRemoteMethod(method);
