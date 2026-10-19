--- electron/spec/api-safe-storage.spec.ts.orig	2026-10-17 02:46:46 UTC
+++ electron/spec/api-safe-storage.spec.ts
@@ -11,7 +11,7 @@ describe('safeStorage module', () => {
 
 describe('safeStorage module', () => {
   beforeAll(() => {
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd') {
       safeStorage.setUsePlainTextEncryption(true);
     }
   });
@@ -29,7 +29,7 @@ describe('safeStorage module', () => {
     });
   });
 
-  ifdescribe(process.platform === 'linux')('SafeStorage.getSelectedStorageBackend()', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('SafeStorage.getSelectedStorageBackend()', () => {
     it('should return a valid backend', () => {
       expect(safeStorage.getSelectedStorageBackend()).toBe('basic_text');
     });
