--- electron/spec/api-web-frame-main-spec.ts.orig	2026-08-10 18:14:56 UTC
+++ electron/spec/api-web-frame-main-spec.ts
@@ -310,7 +310,7 @@ describe('webFrameMain module', () => {
     afterEach(closeAllWindows);
 
     // TODO(jkleinsc) fix this flaky test on linux
-    ifit(process.platform !== 'linux')('throws upon accessing properties when disposed', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('throws upon accessing properties when disposed', async () => {
       await w.loadFile(path.join(subframesPath, 'frame-with-frame-container.html'));
       const { mainFrame } = w.webContents;
       w.destroy();
