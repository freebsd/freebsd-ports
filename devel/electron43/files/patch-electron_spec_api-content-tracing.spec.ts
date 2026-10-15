--- electron/spec/api-content-tracing.spec.ts.orig	2026-10-13 23:40:13 UTC
+++ electron/spec/api-content-tracing.spec.ts
@@ -23,7 +23,7 @@ const fixturesPath = path.resolve(import.meta.dirname,
 const fixturesPath = path.resolve(import.meta.dirname, 'fixtures');
 
 // FIXME: The tests are skipped on linux arm/arm64
-ifdescribe(!['arm', 'arm64'].includes(process.arch) || process.platform !== 'linux')('contentTracing', () => {
+ifdescribe(!['arm', 'arm64'].includes(process.arch) || (process.platform !== 'linux' && process.platform !== 'freebsd'))('contentTracing', () => {
   let pendingRecording: Promise<string> | undefined;
   const record = (
     options: TraceConfig | TraceCategoriesAndOptions,
@@ -120,7 +120,7 @@ ifdescribe(!['arm', 'arm64'].includes(process.arch) ||
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('stopRecording', function () {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('stopRecording', function () {
     this.timeout(recordingTimeout);
 
     // FIXME(samuelmaddock): this test regularly flakes
