--- electron/spec/api-safe-storage-spec.ts.orig	2026-05-08 13:54:01 UTC
+++ electron/spec/api-safe-storage-spec.ts
@@ -15,7 +15,7 @@ describe('safeStorage module', () => {
 
 describe('safeStorage module', () => {
   before(() => {
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd') {
       safeStorage.setUsePlainTextEncryption(true);
     }
   });
@@ -33,7 +33,7 @@ describe('safeStorage module', () => {
     });
   });
 
-  ifdescribe(process.platform === 'linux')('SafeStorage.getSelectedStorageBackend()', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('SafeStorage.getSelectedStorageBackend()', () => {
     it('should return a valid backend', () => {
       expect(safeStorage.getSelectedStorageBackend()).to.equal('basic_text');
     });
