--- electron/spec/api-content-tracing-spec.ts.orig	2025-04-04 05:26:44 UTC
+++ electron/spec/api-content-tracing-spec.ts
@@ -9,7 +9,7 @@ import { ifdescribe } from './lib/spec-helpers';
 import { ifdescribe } from './lib/spec-helpers';
 
 // FIXME: The tests are skipped on linux arm/arm64
-ifdescribe(!(['arm', 'arm64'].includes(process.arch)) || (process.platform !== 'linux'))('contentTracing', () => {
+ifdescribe(!(['arm', 'arm64'].includes(process.arch)) || (process.platform !== 'linux' && process.platform !== 'freebsd'))('contentTracing', () => {
   const record = async (options: TraceConfig | TraceCategoriesAndOptions, outputFilePath: string | undefined, recordTimeInMilliseconds = 1e1) => {
     await app.whenReady();
 
@@ -91,7 +91,7 @@ ifdescribe(!(['arm', 'arm64'].includes(process.arch)) 
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('stopRecording', function () {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('stopRecording', function () {
     if (process.platform === 'win32' && process.arch === 'arm64') {
       // WOA needs more time
       this.timeout(10e3);
