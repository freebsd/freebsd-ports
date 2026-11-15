--- electron/spec/api-content-tracing.spec.ts.orig	2026-10-26 21:12:45 UTC
+++ electron/spec/api-content-tracing.spec.ts
@@ -156,7 +156,7 @@ const getTraceMetadata = (filePath: string) =>
   );
 
 // FIXME: The tests are skipped on linux arm64
-ifdescribe(process.arch !== 'arm64' || process.platform !== 'linux')('contentTracing', () => {
+ifdescribe(process.arch !== 'arm64' || (process.platform !== 'linux' && process.platform !== 'freebsd'))('contentTracing', () => {
   let pendingRecording: Promise<string> | undefined;
   const record = (
     options: TraceConfig | TraceCategoriesAndOptions,
@@ -306,7 +306,7 @@ ifdescribe(process.arch !== 'arm64' || process.platfor
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('stopRecording', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('stopRecording', () => {
     // FIXME(samuelmaddock): this test regularly flakes
     it.skip('does not crash on empty string', async () => {
       const options = {
