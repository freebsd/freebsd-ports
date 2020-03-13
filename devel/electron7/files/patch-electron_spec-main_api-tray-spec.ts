--- electron/spec-main/api-tray-spec.ts.orig	2019-12-13 19:48:14 UTC
+++ electron/spec-main/api-tray-spec.ts
@@ -56,7 +56,7 @@ describe('tray module', () => {
   describe('tray.getBounds()', () => {
     afterEach(() => { tray.destroy() })
 
-    ifit(process.platform !== 'linux') ('returns a bounds object', function () {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd') ('returns a bounds object', function () {
       const bounds = tray.getBounds()
       expect(bounds).to.be.an('object').and.to.have.all.keys('x', 'y', 'width', 'height');
     })
