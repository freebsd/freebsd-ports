--- electron/spec/api-tray.spec.ts.orig	2026-10-15 23:46:52 UTC
+++ electron/spec/api-tray.spec.ts
@@ -32,13 +32,13 @@ describe('tray module', { tags: ['serial'] }, () => {
       }).toThrow(/Failed to load image from path (.+)/);
     });
 
-    ifit(process.platform !== 'linux')('throws a descriptive error if an invalid guid is given', () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('throws a descriptive error if an invalid guid is given', () => {
       expect(() => {
         tray = new Tray(nativeImage.createEmpty(), 'I am not a guid');
       }).toThrow('Invalid GUID format');
     });
 
-    ifit(process.platform !== 'linux')('accepts a valid guid', () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('accepts a valid guid', () => {
       expect(() => {
         tray = new Tray(nativeImage.createEmpty(), '0019A433-3526-48BA-A66C-676742C0FEFB');
       }).not.toThrow();
@@ -139,7 +139,7 @@ describe('tray module', { tags: ['serial'] }, () => {
       tray.destroy();
     });
 
-    ifit(process.platform !== 'linux')('returns a bounds object', () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('returns a bounds object', () => {
       const bounds = tray.getBounds();
       expect(bounds).toBeTypeOf('object');
       expect(Object.keys(bounds).sort()).toEqual(['height', 'width', 'x', 'y']);
