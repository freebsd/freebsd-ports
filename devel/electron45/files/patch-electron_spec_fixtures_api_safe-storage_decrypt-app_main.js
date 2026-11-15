--- electron/spec/fixtures/api/safe-storage/decrypt-app/main.js.orig	2024-10-09 13:53:06 UTC
+++ electron/spec/fixtures/api/safe-storage/decrypt-app/main.js
@@ -7,7 +7,7 @@ app.whenReady().then(async () => {
 const readFile = fs.readFile;
 
 app.whenReady().then(async () => {
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     safeStorage.setUsePlainTextEncryption(true);
   }
   const encryptedString = await readFile(pathToEncryptedString);
