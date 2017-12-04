--- src/VBox/Main/src-server/VirtualBoxImpl.cpp.orig	2015-04-01 12:15:14.000000000 -0400
+++ src/VBox/Main/src-server/VirtualBoxImpl.cpp	2015-04-07 12:25:59.226583000 -0400
@@ -2172,7 +2172,7 @@
     if (aCiphertextSize < 32)
         return VERR_INVALID_PARAMETER;
 
-    AssertCompile(sizeof(m->SettingsCipherKey) >= 32);
+    // AssertCompile(sizeof(m->SettingsCipherKey) >= 32);
 
     /* store the first 8 bytes of the cipherkey for verification */
     for (i = 0, j = 0; i < 8; i++, j++)
