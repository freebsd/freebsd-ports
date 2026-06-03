--- electron/spec/api-content-tracing-spec.ts.orig	2026-05-07 20:19:20 UTC
+++ electron/spec/api-content-tracing-spec.ts
@@ -13,7 +13,7 @@ const fixturesPath = path.resolve(__dirname, 'fixtures
 const fixturesPath = path.resolve(__dirname, 'fixtures');
 
 // FIXME: The tests are skipped on linux arm/arm64
-ifdescribe(!['arm', 'arm64'].includes(process.arch) || process.platform !== 'linux')('contentTracing', () => {
+ifdescribe(!['arm', 'arm64'].includes(process.arch) || (process.platform !== 'linux' && process.platform !== 'freebsd'))('contentTracing', () => {
   const record = async (
     options: TraceConfig | TraceCategoriesAndOptions,
     outputFilePath: string | undefined,
@@ -99,7 +99,7 @@ ifdescribe(!['arm', 'arm64'].includes(process.arch) ||
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('stopRecording', function () {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('stopRecording', function () {
     if (process.platform === 'win32' && process.arch === 'arm64') {
       // WOA needs more time
       this.timeout(10e3);
