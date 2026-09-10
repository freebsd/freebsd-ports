--- electron/spec/api-content-tracing-spec.ts.orig	2026-08-31 00:54:19 UTC
+++ electron/spec/api-content-tracing-spec.ts
@@ -14,7 +14,7 @@ const fixturesPath = path.resolve(__dirname, 'fixtures
 const fixturesPath = path.resolve(__dirname, 'fixtures');
 
 // FIXME: The tests are skipped on linux arm64
-ifdescribe(process.arch !== 'arm64' || process.platform !== 'linux')('contentTracing', () => {
+ifdescribe(process.arch !== 'arm64' || (process.platform !== 'linux' && process.platform !== 'freebsd'))('contentTracing', () => {
   const record = async (
     options: TraceConfig | TraceCategoriesAndOptions,
     outputFilePath: string | undefined,
@@ -107,7 +107,7 @@ ifdescribe(process.arch !== 'arm64' || process.platfor
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('stopRecording', function () {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('stopRecording', function () {
     if (process.platform === 'win32' && process.arch === 'arm64') {
       // WOA needs more time
       this.timeout(10e3);
