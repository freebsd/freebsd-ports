--- electron/spec-main/api-subframe-spec.ts.orig	2021-01-22 23:55:24 UTC
+++ electron/spec-main/api-subframe-spec.ts
@@ -177,7 +177,7 @@ describe('renderer nodeIntegrationInSubFrames', () => 
 });
 
 // app.getAppMetrics() does not return sandbox information on Linux.
-ifdescribe(process.platform !== 'linux')('cross-site frame sandboxing', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('cross-site frame sandboxing', () => {
   let server: http.Server;
   let crossSiteUrl: string;
   let serverUrl: string;
