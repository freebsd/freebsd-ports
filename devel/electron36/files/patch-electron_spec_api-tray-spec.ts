--- electron/spec/api-tray-spec.ts.orig	2025-09-08 12:48:33 UTC
+++ electron/spec/api-tray-spec.ts
@@ -30,13 +30,13 @@ describe('tray module', () => {
       }).to.throw(/Failed to load image from path (.+)/);
     });
 
-    ifit(process.platform !== 'linux')('throws a descriptive error if an invalid guid is given', () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('throws a descriptive error if an invalid guid is given', () => {
       expect(() => {
         tray = new Tray(nativeImage.createEmpty(), 'I am not a guid');
       }).to.throw('Invalid GUID format');
     });
 
-    ifit(process.platform !== 'linux')('accepts a valid guid', () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('accepts a valid guid', () => {
       expect(() => {
         tray = new Tray(nativeImage.createEmpty(), '0019A433-3526-48BA-A66C-676742C0FEFB');
       }).to.not.throw();
@@ -131,7 +131,7 @@ describe('tray module', () => {
   describe('tray.getBounds()', () => {
     afterEach(() => { tray.destroy(); });
 
-    ifit(process.platform !== 'linux')('returns a bounds object', function () {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('returns a bounds object', function () {
       const bounds = tray.getBounds();
       expect(bounds).to.be.an('object').and.to.have.all.keys('x', 'y', 'width', 'height');
     });
