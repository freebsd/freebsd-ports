--- electron/spec-main/api-subframe-spec.ts.orig	2020-05-18 21:17:08 UTC
+++ electron/spec-main/api-subframe-spec.ts
@@ -177,7 +177,7 @@ describe('renderer nodeIntegrationInSubFrames', () => 
 });
 
 // app.getAppMetrics() does not return sandbox information on Linux.
-ifdescribe(process.platform !== 'linux')('cross-site frame sandboxing', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('cross-site frame sandboxing', () => {
   let server: http.Server;
   let crossSiteUrl: string;
   let serverUrl: string;
