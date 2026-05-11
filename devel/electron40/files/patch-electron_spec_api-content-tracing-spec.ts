--- electron/spec/api-content-tracing-spec.ts.orig	2026-05-08 13:55:13 UTC
+++ electron/spec/api-content-tracing-spec.ts
@@ -9,7 +9,7 @@ import { ifdescribe } from './lib/spec-helpers';
 import { ifdescribe } from './lib/spec-helpers';
 
 // FIXME: The tests are skipped on linux arm/arm64
-ifdescribe(!['arm', 'arm64'].includes(process.arch) || process.platform !== 'linux')('contentTracing', () => {
+ifdescribe(!['arm', 'arm64'].includes(process.arch) || (process.platform !== 'linux' && process.platform !== 'freebsd'))('contentTracing', () => {
   const record = async (
     options: TraceConfig | TraceCategoriesAndOptions,
     outputFilePath: string | undefined,
@@ -95,7 +95,7 @@ ifdescribe(!['arm', 'arm64'].includes(process.arch) ||
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('stopRecording', function () {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('stopRecording', function () {
     if (process.platform === 'win32' && process.arch === 'arm64') {
       // WOA needs more time
       this.timeout(10e3);
