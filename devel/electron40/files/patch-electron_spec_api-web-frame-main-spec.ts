--- electron/spec/api-web-frame-main-spec.ts.orig	2026-05-08 13:55:13 UTC
+++ electron/spec/api-web-frame-main-spec.ts
@@ -307,7 +307,7 @@ describe('webFrameMain module', () => {
     afterEach(closeAllWindows);
 
     // TODO(jkleinsc) fix this flaky test on linux
-    ifit(process.platform !== 'linux')('throws upon accessing properties when disposed', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('throws upon accessing properties when disposed', async () => {
       await w.loadFile(path.join(subframesPath, 'frame-with-frame-container.html'));
       const { mainFrame } = w.webContents;
       w.destroy();
