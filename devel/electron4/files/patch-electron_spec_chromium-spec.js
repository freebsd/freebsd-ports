--- electron/spec/chromium-spec.js.orig	2019-05-14 03:32:31 UTC
+++ electron/spec/chromium-spec.js
@@ -861,7 +861,7 @@ describe('chromium feature', () => {
     })
 
     it('can be get as context in canvas', () => {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // FIXME(alexeykuzmin): Skip the test.
         // this.skip()
         return
