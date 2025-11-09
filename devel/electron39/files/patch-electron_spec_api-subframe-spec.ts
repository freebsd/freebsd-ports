--- electron/spec/api-subframe-spec.ts.orig	2025-09-02 20:56:04 UTC
+++ electron/spec/api-subframe-spec.ts
@@ -247,7 +247,7 @@ describe('subframe with non-standard schemes', () => {
 });
 
 // app.getAppMetrics() does not return sandbox information on Linux.
-ifdescribe(process.platform !== 'linux')('cross-site frame sandboxing', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('cross-site frame sandboxing', () => {
   let server: http.Server;
   let crossSiteUrl: string;
   let serverUrl: string;
