--- src/applications/files/builtin/PhabricatorFilesComposeAvatarBuiltinFile.php.orig	2023-11-13 19:04:04 UTC
+++ src/applications/files/builtin/PhabricatorFilesComposeAvatarBuiltinFile.php
@@ -184,11 +184,11 @@ final class PhabricatorFilesComposeAvatarBuiltinFile
   }
 
   private static function rgba2gd(array $rgba) {
-    $r = (int)$rgba[0];
-    $g = (int)$rgba[1];
-    $b = (int)$rgba[2];
-    $a = (int)$rgba[3];
-    $a = (1 - $a) * 255;
+    $r = $rgba[0];
+    $g = $rgba[1];
+    $b = $rgba[2];
+    $a = $rgba[3];
+    $a = round(((1 - $a) * 255), 0);
     return ($a << 24) | ($r << 16) | ($g << 8) | $b;
   }
 
