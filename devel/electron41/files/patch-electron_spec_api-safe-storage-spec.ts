--- electron/spec/api-safe-storage-spec.ts.orig	2026-05-07 20:19:20 UTC
+++ electron/spec/api-safe-storage-spec.ts
@@ -33,7 +33,7 @@ describe('safeStorage module', () => {
 
 describe('safeStorage module', () => {
   before(() => {
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd') {
       safeStorage.setUsePlainTextEncryption(true);
     }
   });
@@ -51,7 +51,7 @@ describe('safeStorage module', () => {
     });
   });
 
-  ifdescribe(process.platform === 'linux')('SafeStorage.getSelectedStorageBackend()', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('SafeStorage.getSelectedStorageBackend()', () => {
     it('should return a valid backend', () => {
       expect(safeStorage.getSelectedStorageBackend()).to.equal('basic_text');
     });
