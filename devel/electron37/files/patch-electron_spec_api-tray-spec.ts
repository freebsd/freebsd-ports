--- electron/spec/api-tray-spec.ts.orig	2024-10-09 13:53:06 UTC
+++ electron/spec/api-tray-spec.ts
@@ -131,7 +131,7 @@ describe('tray module', () => {
   describe('tray.getBounds()', () => {
     afterEach(() => { tray.destroy(); });
 
-    ifit(process.platform !== 'linux')('returns a bounds object', function () {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('returns a bounds object', function () {
       const bounds = tray.getBounds();
       expect(bounds).to.be.an('object').and.to.have.all.keys('x', 'y', 'width', 'height');
     });
