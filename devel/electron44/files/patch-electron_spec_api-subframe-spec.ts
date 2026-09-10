--- electron/spec/api-subframe-spec.ts.orig	2026-05-07 20:19:20 UTC
+++ electron/spec/api-subframe-spec.ts
@@ -248,7 +248,7 @@ describe('subframe with non-standard schemes', () => {
 });
 
 // app.getAppMetrics() does not return sandbox information on Linux.
-ifdescribe(process.platform !== 'linux')('cross-site frame sandboxing', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('cross-site frame sandboxing', () => {
   let server: http.Server;
   let crossSiteUrl: string;
   let serverUrl: string;
