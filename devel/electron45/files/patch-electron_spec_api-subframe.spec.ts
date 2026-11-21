--- electron/spec/api-subframe.spec.ts.orig	2026-11-18 23:46:22 UTC
+++ electron/spec/api-subframe.spec.ts
@@ -254,7 +254,7 @@ describe('subframe with non-standard schemes', { retry
 });
 
 // app.getAppMetrics() does not return sandbox information on Linux.
-ifdescribe(process.platform !== 'linux')('cross-site frame sandboxing', { retry: 0 }, () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('cross-site frame sandboxing', { retry: 0 }, () => {
   let server: http.Server;
   let crossSiteUrl: string;
   let serverUrl: string;
