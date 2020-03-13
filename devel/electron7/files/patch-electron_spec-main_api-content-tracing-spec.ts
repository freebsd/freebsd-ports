--- electron/spec-main/api-content-tracing-spec.ts.orig	2019-12-13 19:48:14 UTC
+++ electron/spec-main/api-content-tracing-spec.ts
@@ -11,7 +11,7 @@ const timeout = async (milliseconds: number) => {
 }
 
 // FIXME: The tests are skipped on arm/arm64.
-ifdescribe(!(process.platform === 'linux' && ['arm', 'arm64'].includes(process.arch)))('contentTracing', () => {
+ifdescribe(!((process.platform === 'linux' || process.platform === 'freebsd') && ['arm', 'arm64'].includes(process.arch)))('contentTracing', () => {
   const record = async (options: TraceConfig | TraceCategoriesAndOptions, outputFilePath: string | undefined, recordTimeInMilliseconds = 1e1) => {
     await app.whenReady()
 
