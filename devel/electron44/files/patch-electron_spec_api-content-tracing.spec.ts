--- electron/spec/api-content-tracing.spec.ts.orig	2026-09-29 23:27:57 UTC
+++ electron/spec/api-content-tracing.spec.ts
@@ -23,7 +23,7 @@ const fixturesPath = path.resolve(import.meta.dirname,
 const fixturesPath = path.resolve(import.meta.dirname, 'fixtures');
 
 // FIXME: The tests are skipped on linux arm64
-ifdescribe(process.arch !== 'arm64' || process.platform !== 'linux')('contentTracing', () => {
+ifdescribe(process.arch !== 'arm64' || (process.platform !== 'linux' && process.platform !== 'freebsd'))('contentTracing', () => {
   const record = async (
     options: TraceConfig | TraceCategoriesAndOptions,
     outputFilePath: string | undefined,
@@ -116,7 +116,7 @@ ifdescribe(process.arch !== 'arm64' || process.platfor
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('stopRecording', function () {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('stopRecording', function () {
     if (process.platform === 'win32' && process.arch === 'arm64') {
       // WOA needs more time
       this.timeout(10e3);
