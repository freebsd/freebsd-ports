--- electron/spec/api-auto-updater-spec.js.orig	2019-05-16 02:00:37 UTC
+++ electron/spec/api-auto-updater-spec.js
@@ -140,7 +140,7 @@ describe('autoUpdater module', function () {
 
   describe('error event', () => {
     it('serializes correctly over the remote module', function (done) {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // FIXME(alexeykuzmin): Skip the test.
         // this.skip()
         return done()
