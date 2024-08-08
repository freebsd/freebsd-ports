--- electron/spec/api-subframe-spec.ts.orig	2023-12-04 18:19:02 UTC
+++ electron/spec/api-subframe-spec.ts
@@ -215,7 +215,7 @@ describe('renderer nodeIntegrationInSubFrames', () => 
 });
 
 // app.getAppMetrics() does not return sandbox information on Linux.
-ifdescribe(process.platform !== 'linux')('cross-site frame sandboxing', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('cross-site frame sandboxing', () => {
   let server: http.Server;
   let crossSiteUrl: string;
   let serverUrl: string;
