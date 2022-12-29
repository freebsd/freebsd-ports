--- electron/spec-main/fixtures/crash-cases/safe-storage/index.js.orig	2022-05-18 15:31:32 UTC
+++ electron/spec-main/fixtures/crash-cases/safe-storage/index.js
@@ -21,7 +21,7 @@ const { expect } = require('chai');
   await app.whenReady();
   // isEncryptionAvailable() will always return false on CI due to a mocked
   // dbus as mentioned above.
-  expect(safeStorage.isEncryptionAvailable()).to.equal(process.platform !== 'linux');
+  expect(safeStorage.isEncryptionAvailable()).to.equal(process.platform !== 'linux' && process.platform !== 'freebsd');
   if (safeStorage.isEncryptionAvailable()) {
     const plaintext = 'plaintext';
     const ciphertext = safeStorage.encryptString(plaintext);
