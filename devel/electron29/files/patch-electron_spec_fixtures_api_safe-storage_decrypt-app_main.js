--- electron/spec/fixtures/api/safe-storage/decrypt-app/main.js.orig	2023-08-12 11:44:47 UTC
+++ electron/spec/fixtures/api/safe-storage/decrypt-app/main.js
@@ -6,7 +6,7 @@ const pathToEncryptedString = path.resolve(__dirname, 
 const readFile = fs.readFile;
 
 app.whenReady().then(async () => {
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     safeStorage.setUsePlainTextEncryption(true);
   }
   const encryptedString = await readFile(pathToEncryptedString);
