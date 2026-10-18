--- electron/spec/api-content-tracing.spec.ts.orig	2026-10-15 23:46:52 UTC
+++ electron/spec/api-content-tracing.spec.ts
@@ -23,7 +23,7 @@ const fixturesPath = path.resolve(import.meta.dirname,
 const fixturesPath = path.resolve(import.meta.dirname, 'fixtures');
 
 // FIXME: The tests are skipped on linux arm/arm64
-ifdescribe(!['arm', 'arm64'].includes(process.arch) || process.platform !== 'linux')('contentTracing', () => {
+ifdescribe(!['arm', 'arm64'].includes(process.arch) || (process.platform !== 'linux' && process.platform !== 'freebsd'))('contentTracing', () => {
   let pendingRecording: Promise<string> | undefined;
   const record = (
     options: TraceConfig | TraceCategoriesAndOptions,
@@ -118,7 +118,7 @@ ifdescribe(!['arm', 'arm64'].includes(process.arch) ||
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('stopRecording', { timeout: recordingTimeout }, () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('stopRecording', { timeout: recordingTimeout }, () => {
     // FIXME(samuelmaddock): this test regularly flakes
     it.skip('does not crash on empty string', async () => {
       const options = {
