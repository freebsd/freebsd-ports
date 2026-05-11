--- electron/spec/fixtures/crash-cases/safe-storage/index.js.orig	2026-05-08 13:55:13 UTC
+++ electron/spec/fixtures/crash-cases/safe-storage/index.js
@@ -24,7 +24,7 @@ const { expect } = require('chai');
   await app.whenReady();
   // isEncryptionAvailable() will always return false on CI due to a mocked
   // dbus as mentioned above.
-  expect(safeStorage.isEncryptionAvailable()).to.equal(process.platform !== 'linux');
+  expect(safeStorage.isEncryptionAvailable()).to.equal(process.platform !== 'linux' && process.platform !== 'freebsd');
   if (safeStorage.isEncryptionAvailable()) {
     const plaintext = 'plaintext';
     const ciphertext = safeStorage.encryptString(plaintext);
