--- electron/spec/api-safe-storage.spec.ts.orig	2026-10-26 21:12:45 UTC
+++ electron/spec/api-safe-storage.spec.ts
@@ -12,7 +12,7 @@ describe('safeStorage module', () => {
 
 describe('safeStorage module', () => {
   beforeAll(() => {
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd') {
       safeStorage.setUsePlainTextEncryption(true);
     }
   });
@@ -42,7 +42,7 @@ describe('safeStorage module', () => {
     });
   });
 
-  ifdescribe(process.platform === 'linux')('SafeStorage.getSelectedStorageBackend()', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('SafeStorage.getSelectedStorageBackend()', () => {
     it('should return a valid backend', () => {
       expect(safeStorage.getSelectedStorageBackend()).toBe('basic_text');
     });
