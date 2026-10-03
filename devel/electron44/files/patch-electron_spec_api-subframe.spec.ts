--- electron/spec/api-subframe.spec.ts.orig	2026-09-29 23:27:57 UTC
+++ electron/spec/api-subframe.spec.ts
@@ -254,7 +254,7 @@ describe('subframe with non-standard schemes', () => {
 });
 
 // app.getAppMetrics() does not return sandbox information on Linux.
-ifdescribe(process.platform !== 'linux')('cross-site frame sandboxing', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('cross-site frame sandboxing', () => {
   let server: http.Server;
   let crossSiteUrl: string;
   let serverUrl: string;
