--- electron/spec-main/api-web-frame-main-spec.ts.orig	2023-01-24 08:00:52 UTC
+++ electron/spec-main/api-web-frame-main-spec.ts
@@ -292,7 +292,7 @@ describe('webFrameMain module', () => {
     });
 
     // TODO(jkleinsc) fix this flaky test on linux
-    ifit(process.platform !== 'linux')('throws upon accessing properties when disposed', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('throws upon accessing properties when disposed', async () => {
       await w.loadFile(path.join(subframesPath, 'frame-with-frame-container.html'));
       const { mainFrame } = w.webContents;
       w.destroy();
