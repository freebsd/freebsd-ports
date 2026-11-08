--- electron/spec/api-web-contents.spec.ts.orig	2026-10-30 06:33:33 UTC
+++ electron/spec/api-web-contents.spec.ts
@@ -1647,7 +1647,7 @@ describe('webContents module', () => {
     // back to OpenFolder() which does a blocking DirectoryExists() on the UI
     // thread (pre-existing behavior). Workspace-gating is covered by the test
     // above.
-    ifit(process.platform !== 'linux')(
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')(
       'reveals paths under a registered workspace folder without executing them',
       // Opens a real Finder/Explorer window, which takes focus and stays open.
       { tags: ['serial'] },
@@ -1673,7 +1673,7 @@ describe('webContents module', () => {
   // xdg-desktop-portal FileChooser that script/dbus_mock.py hosts on the fake
   // session bus.
   ifdescribe(
-    process.platform === 'linux' &&
+    (process.platform === 'linux' || process.platform === 'freebsd') &&
       process.arch !== 'ia32' &&
       !process.arch.startsWith('arm') &&
       !!process.env.DBUS_SESSION_BUS_ADDRESS
@@ -5411,7 +5411,7 @@ describe('webContents module', () => {
     });
 
     // TODO(codebytere): OOPIF printing is disabled on Linux at the moment due to crashes.
-    ifit(process.platform !== 'linux')('can print cross-origin iframes', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('can print cross-origin iframes', async () => {
       server = http.createServer((_, res) => {
         res.writeHead(200);
         res.end(`
