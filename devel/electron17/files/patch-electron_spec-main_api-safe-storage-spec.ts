--- electron/spec-main/api-safe-storage-spec.ts.orig	2021-11-15 23:45:07 UTC
+++ electron/spec-main/api-safe-storage-spec.ts
@@ -14,7 +14,7 @@ import * as fs from 'fs';
 * when run on CI and linux.
 */
 
-ifdescribe(process.platform !== 'linux')('safeStorage module', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('safeStorage module', () => {
   after(async () => {
     const pathToEncryptedString = path.resolve(__dirname, 'fixtures', 'api', 'safe-storage', 'encrypted.txt');
     if (fs.existsSync(pathToEncryptedString)) {
