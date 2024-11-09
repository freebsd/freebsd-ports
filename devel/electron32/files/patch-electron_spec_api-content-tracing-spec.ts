--- electron/spec/api-content-tracing-spec.ts.orig	2024-10-09 13:53:06 UTC
+++ electron/spec/api-content-tracing-spec.ts
@@ -9,7 +9,7 @@ import { ifdescribe } from './lib/spec-helpers';
 import { ifdescribe } from './lib/spec-helpers';
 
 // FIXME: The tests are skipped on linux arm/arm64
-ifdescribe(!(['arm', 'arm64'].includes(process.arch)) || (process.platform !== 'linux'))('contentTracing', () => {
+ifdescribe(!(['arm', 'arm64'].includes(process.arch)) || (process.platform !== 'linux' && process.platform !== 'freebsd'))('contentTracing', () => {
   const record = async (options: TraceConfig | TraceCategoriesAndOptions, outputFilePath: string | undefined, recordTimeInMilliseconds = 1e1) => {
     await app.whenReady();
 
