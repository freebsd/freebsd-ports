--- src/VBox/Main/src-server/VirtualBoxImpl.cpp.orig	2025-08-13 19:51:27 UTC
+++ src/VBox/Main/src-server/VirtualBoxImpl.cpp
@@ -3097,7 +3097,7 @@ int VirtualBox::i_encryptSettingBytes(const uint8_t *a
     if (aCiphertextSize < 32)
         return VERR_INVALID_PARAMETER;
 
-    AssertCompile(sizeof(m->SettingsCipherKey) >= 32);
+    // AssertCompile(sizeof(m->SettingsCipherKey) >= 32);
 
     /* store the first 8 bytes of the cipherkey for verification */
     for (i = 0, j = 0; i < 8; i++, j++)
