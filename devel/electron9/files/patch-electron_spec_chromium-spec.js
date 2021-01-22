--- electron/spec/chromium-spec.js.orig	2020-12-11 21:16:23 UTC
+++ electron/spec/chromium-spec.js
@@ -269,7 +269,7 @@ describe('chromium feature', () => {
     });
 
     it('can be get as context in canvas', () => {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // FIXME(alexeykuzmin): Skip the test.
         // this.skip()
         return;
