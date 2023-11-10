--- src/applications/files/builtin/PhabricatorFilesComposeAvatarBuiltinFile.php.orig	2021-12-18 19:11:09 UTC
+++ src/applications/files/builtin/PhabricatorFilesComposeAvatarBuiltinFile.php
@@ -188,7 +188,7 @@ final class PhabricatorFilesComposeAvatarBuiltinFile
     $g = $rgba[1];
     $b = $rgba[2];
     $a = $rgba[3];
-    $a = (1 - $a) * 255;
+    $a = round(((1 - $a) * 255), 0);
     return ($a << 24) | ($r << 16) | ($g << 8) | $b;
   }
 
