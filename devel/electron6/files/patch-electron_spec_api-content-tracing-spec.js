--- electron/spec/api-content-tracing-spec.js.orig	2019-09-11 17:30:11 UTC
+++ electron/spec/api-content-tracing-spec.js
@@ -22,7 +22,7 @@ const getPathInATempFolder = (filename) => {
 describe('contentTracing', () => {
   beforeEach(function () {
     // FIXME: The tests are skipped on arm/arm64.
-    if (process.platform === 'linux' &&
+    if ((process.platform === 'linux' || process.platform === 'freebsd') &&
         ['arm', 'arm64'].includes(process.arch)) {
       this.skip()
     }
