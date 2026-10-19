--- electron/spec/api-content-tracing.spec.ts.orig	2026-10-17 02:46:46 UTC
+++ electron/spec/api-content-tracing.spec.ts
@@ -23,7 +23,7 @@ const fixturesPath = path.resolve(import.meta.dirname,
 const fixturesPath = path.resolve(import.meta.dirname, 'fixtures');
 
 // FIXME: The tests are skipped on linux arm64
-ifdescribe(process.arch !== 'arm64' || process.platform !== 'linux')('contentTracing', () => {
+ifdescribe(process.arch !== 'arm64' || (process.platform !== 'linux' && process.platform !== 'freebsd'))('contentTracing', () => {
   let pendingRecording: Promise<string> | undefined;
   const record = (
     options: TraceConfig | TraceCategoriesAndOptions,
@@ -120,7 +120,7 @@ ifdescribe(process.arch !== 'arm64' || process.platfor
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('stopRecording', { timeout: recordingTimeout }, () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('stopRecording', { timeout: recordingTimeout }, () => {
     // FIXME(samuelmaddock): this test regularly flakes
     it.skip('does not crash on empty string', async () => {
       const options = {
