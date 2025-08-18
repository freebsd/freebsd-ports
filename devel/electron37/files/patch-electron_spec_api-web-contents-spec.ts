--- electron/spec/api-web-contents-spec.ts.orig	2025-08-13 14:21:20 UTC
+++ electron/spec/api-web-contents-spec.ts
@@ -2797,7 +2797,7 @@ describe('webContents module', () => {
     });
 
     // TODO(codebytere): OOPIF printing is disabled on Linux at the moment due to crashes.
-    ifit(process.platform !== 'linux')('can print cross-origin iframes', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('can print cross-origin iframes', async () => {
       server = http.createServer((_, res) => {
         res.writeHead(200);
         res.end(`
