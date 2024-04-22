--- electron/spec/api-content-tracing-spec.ts.orig	2023-09-16 04:46:51 UTC
+++ electron/spec/api-content-tracing-spec.ts
@@ -6,7 +6,7 @@ import { setTimeout } from 'timers/promises';
 import { ifdescribe } from './lib/spec-helpers';
 
 // FIXME: The tests are skipped on linux arm/arm64
-ifdescribe(!(['arm', 'arm64'].includes(process.arch)) || (process.platform !== 'linux'))('contentTracing', () => {
+ifdescribe(!(['arm', 'arm64'].includes(process.arch)) || (process.platform !== 'linux' && process.platform !== 'freebsd'))('contentTracing', () => {
   const record = async (options: TraceConfig | TraceCategoriesAndOptions, outputFilePath: string | undefined, recordTimeInMilliseconds = 1e1) => {
     await app.whenReady();
 
