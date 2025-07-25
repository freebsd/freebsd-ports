--- electron/spec/api-web-frame-main-spec.ts.orig	2025-07-22 07:50:49 UTC
+++ electron/spec/api-web-frame-main-spec.ts
@@ -316,7 +316,7 @@ describe('webFrameMain module', () => {
     afterEach(closeAllWindows);
 
     // TODO(jkleinsc) fix this flaky test on linux
-    ifit(process.platform !== 'linux')('throws upon accessing properties when disposed', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('throws upon accessing properties when disposed', async () => {
       await w.loadFile(path.join(subframesPath, 'frame-with-frame-container.html'));
       const { mainFrame } = w.webContents;
       w.destroy();
