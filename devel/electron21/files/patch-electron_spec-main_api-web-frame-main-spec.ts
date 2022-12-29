--- electron/spec-main/api-web-frame-main-spec.ts.orig	2022-05-18 15:31:32 UTC
+++ electron/spec-main/api-web-frame-main-spec.ts
@@ -204,7 +204,7 @@ describe('webFrameMain module', () => {
     });
 
     // TODO(jkleinsc) fix this flaky test on linux
-    ifit(process.platform !== 'linux')('throws upon accessing properties when disposed', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('throws upon accessing properties when disposed', async () => {
       await w.loadFile(path.join(subframesPath, 'frame-with-frame-container.html'));
       const { mainFrame } = w.webContents;
       w.destroy();
