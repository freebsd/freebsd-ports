--- electron/spec/api-content-tracing.spec.ts.orig	2026-09-30 08:48:04 UTC
+++ electron/spec/api-content-tracing.spec.ts
@@ -23,7 +23,7 @@ const fixturesPath = path.resolve(import.meta.dirname,
 const fixturesPath = path.resolve(import.meta.dirname, 'fixtures');
 
 // FIXME: The tests are skipped on linux arm/arm64
-ifdescribe(!['arm', 'arm64'].includes(process.arch) || process.platform !== 'linux')('contentTracing', () => {
+ifdescribe(!['arm', 'arm64'].includes(process.arch) || (process.platform !== 'linux' && process.platform !== 'freebsd'))('contentTracing', () => {
   const record = async (
     options: TraceConfig | TraceCategoriesAndOptions,
     outputFilePath: string | undefined,
@@ -114,7 +114,7 @@ ifdescribe(!['arm', 'arm64'].includes(process.arch) ||
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('stopRecording', function () {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('stopRecording', function () {
     if (process.platform === 'win32' && process.arch === 'arm64') {
       // WOA needs more time
       this.timeout(10e3);
