--- electron/lib/common/api/clipboard.ts.orig	2023-01-24 16:58:16 UTC
+++ electron/lib/common/api/clipboard.ts
@@ -12,7 +12,7 @@ if (process.type === 'renderer') {
     return (...args: any[]) => ipcRendererUtils.invokeSync(IPC_MESSAGES.BROWSER_CLIPBOARD_SYNC, method, ...args);
   };
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     // On Linux we could not access clipboard in renderer process.
     for (const method of Object.keys(clipboard) as (keyof Electron.Clipboard)[]) {
       clipboard[method] = makeRemoteMethod(method);
