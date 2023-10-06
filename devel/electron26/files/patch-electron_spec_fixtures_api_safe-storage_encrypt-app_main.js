--- electron/spec/fixtures/api/safe-storage/encrypt-app/main.js.orig	2023-08-12 11:45:22 UTC
+++ electron/spec/fixtures/api/safe-storage/encrypt-app/main.js
@@ -6,7 +6,7 @@ const pathToEncryptedString = path.resolve(__dirname, 
 const writeFile = fs.writeFile;
 
 app.whenReady().then(async () => {
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     safeStorage.setUsePlainTextEncryption(true);
   }
   const encrypted = safeStorage.encryptString('plaintext');
