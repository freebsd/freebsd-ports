--- electron/spec-main/api-tray-spec.ts.orig	2020-04-29 19:04:02 UTC
+++ electron/spec-main/api-tray-spec.ts
@@ -63,7 +63,7 @@ describe('tray module', () => {
   describe('tray.getBounds()', () => {
     afterEach(() => { tray.destroy() })
 
-    ifit(process.platform !== 'linux') ('returns a bounds object', function () {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd') ('returns a bounds object', function () {
       const bounds = tray.getBounds()
       expect(bounds).to.be.an('object').and.to.have.all.keys('x', 'y', 'width', 'height');
     })
