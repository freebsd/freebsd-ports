--- electron/spec/fixtures/crash-cases/safe-storage/index.js.orig	2024-10-09 13:53:06 UTC
+++ electron/spec/fixtures/crash-cases/safe-storage/index.js
@@ -22,7 +22,7 @@ const { expect } = require('chai');
   await app.whenReady();
   // isEncryptionAvailable() will always return false on CI due to a mocked
   // dbus as mentioned above.
-  expect(safeStorage.isEncryptionAvailable()).to.equal(process.platform !== 'linux');
+  expect(safeStorage.isEncryptionAvailable()).to.equal(process.platform !== 'linux' && process.platform !== 'freebsd');
   if (safeStorage.isEncryptionAvailable()) {
     const plaintext = 'plaintext';
     const ciphertext = safeStorage.encryptString(plaintext);
