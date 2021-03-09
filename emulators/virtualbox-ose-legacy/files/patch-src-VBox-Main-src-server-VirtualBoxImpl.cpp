--- src/VBox/Main/src-server/VirtualBoxImpl.cpp.orig	2020-05-13 19:44:10 UTC
+++ src/VBox/Main/src-server/VirtualBoxImpl.cpp
@@ -2251,7 +2251,7 @@ int VirtualBox::i_encryptSettingBytes(const uint8_t *a
     if (aCiphertextSize < 32)
         return VERR_INVALID_PARAMETER;
 
-    AssertCompile(sizeof(m->SettingsCipherKey) >= 32);
+    // AssertCompile(sizeof(m->SettingsCipherKey) >= 32);
 
     /* store the first 8 bytes of the cipherkey for verification */
     for (i = 0, j = 0; i < 8; i++, j++)
