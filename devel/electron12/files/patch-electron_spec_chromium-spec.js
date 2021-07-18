--- electron/spec/chromium-spec.js.orig	2021-04-20 23:32:33 UTC
+++ electron/spec/chromium-spec.js
@@ -234,7 +234,7 @@ describe('chromium feature', () => {
     });
 
     it('can be get as context in canvas', () => {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // FIXME(alexeykuzmin): Skip the test.
         // this.skip()
         return;
