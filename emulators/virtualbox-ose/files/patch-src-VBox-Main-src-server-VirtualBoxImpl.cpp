--- src/VBox/Main/src-server/VirtualBoxImpl.cpp.orig	2013-12-18 11:10:25.000000000 -0500
+++ src/VBox/Main/src-server/VirtualBoxImpl.cpp	2014-02-20 19:51:23.000000000 -0500
@@ -2355,7 +2355,7 @@
     if (aCiphertextSize < 32)
         return VERR_INVALID_PARAMETER;
 
-    AssertCompile(sizeof(m->SettingsCipherKey) >= 32);
+    // AssertCompile(sizeof(m->SettingsCipherKey) >= 32);
 
     /* store the first 8 bytes of the cipherkey for verification */
     for (i = 0, j = 0; i < 8; i++, j++)
