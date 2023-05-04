--- electron/spec/api-safe-storage-spec.ts.orig	2023-01-24 16:58:16 UTC
+++ electron/spec/api-safe-storage-spec.ts
@@ -33,7 +33,7 @@ describe('safeStorage module', () => {
   });
 });
 
-ifdescribe(process.platform !== 'linux')('safeStorage module', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('safeStorage module', () => {
   after(async () => {
     const pathToEncryptedString = path.resolve(__dirname, 'fixtures', 'api', 'safe-storage', 'encrypted.txt');
     if (await fs.pathExists(pathToEncryptedString)) {
