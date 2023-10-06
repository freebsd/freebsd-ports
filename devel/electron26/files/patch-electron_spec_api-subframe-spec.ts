--- electron/spec/api-subframe-spec.ts.orig	2021-04-20 23:32:33 UTC
+++ electron/spec/api-subframe-spec.ts
@@ -213,7 +213,7 @@ describe('renderer nodeIntegrationInSubFrames', () => 
 });
 
 // app.getAppMetrics() does not return sandbox information on Linux.
-ifdescribe(process.platform !== 'linux')('cross-site frame sandboxing', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('cross-site frame sandboxing', () => {
   let server: http.Server;
   let crossSiteUrl: string;
   let serverUrl: string;
