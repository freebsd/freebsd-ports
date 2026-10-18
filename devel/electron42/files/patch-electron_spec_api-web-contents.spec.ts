--- electron/spec/api-web-contents.spec.ts.orig	2026-10-15 23:46:52 UTC
+++ electron/spec/api-web-contents.spec.ts
@@ -1474,7 +1474,7 @@ describe('webContents module', () => {
     // back to OpenFolder() which does a blocking DirectoryExists() on the UI
     // thread (pre-existing behavior). Workspace-gating is covered by the test
     // above.
-    ifit(process.platform !== 'linux')(
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')(
       'reveals paths under a registered workspace folder without executing them',
       async () => {
         const w = new BrowserWindow({ show: false });
@@ -3484,7 +3484,7 @@ describe('webContents module', () => {
     });
 
     // TODO(codebytere): OOPIF printing is disabled on Linux at the moment due to crashes.
-    ifit(process.platform !== 'linux')('can print cross-origin iframes', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('can print cross-origin iframes', async () => {
       server = http.createServer((_, res) => {
         res.writeHead(200);
         res.end(`
