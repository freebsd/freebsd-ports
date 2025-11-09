--- electron/spec/api-web-contents-spec.ts.orig	2025-10-27 17:58:27 UTC
+++ electron/spec/api-web-contents-spec.ts
@@ -2815,7 +2815,7 @@ describe('webContents module', () => {
     });
 
     // TODO(codebytere): OOPIF printing is disabled on Linux at the moment due to crashes.
-    ifit(process.platform !== 'linux')('can print cross-origin iframes', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('can print cross-origin iframes', async () => {
       server = http.createServer((_, res) => {
         res.writeHead(200);
         res.end(`
