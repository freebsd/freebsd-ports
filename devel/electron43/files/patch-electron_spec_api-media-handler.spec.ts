--- electron/spec/api-media-handler.spec.ts.orig	2026-10-16 03:32:58 UTC
+++ electron/spec/api-media-handler.spec.ts
@@ -64,7 +64,7 @@ describe('setDisplayMediaRequestHandler', () => {
 
   // Process-level loopback audio capture (restrictOwnAudio / loopbackWithoutChrome)
   // is not supported on Linux audio backends (PulseAudio / PipeWire).
-  ifit(process.platform !== 'linux')(
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')(
     'honors the restrictOwnAudio constraint when granted loopback audio',
     async (ctx) => {
       if ((await desktopCapturer.getSources({ types: ['screen'] })).length === 0) {
