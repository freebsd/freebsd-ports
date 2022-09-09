--- src/parser/ArcanistBundle.php.orig	2022-09-08 16:04:09 UTC
+++ src/parser/ArcanistBundle.php
@@ -762,7 +762,7 @@ final class ArcanistBundle extends Phobject {
       $old_data = $this->getBlob($old_phid, $name);
     }
 
-    $old_length = strlen($old_data);
+    $old_length = strlen($old_data ?? '');
 
     // Here, and below, the binary will be emitted with base85 encoding. This
     // encoding encodes each 4 bytes of input in 5 bytes of output, so we may
@@ -795,7 +795,7 @@ final class ArcanistBundle extends Phobject {
       $new_data = $this->getBlob($new_phid, $name);
     }
 
-    $new_length = strlen($new_data);
+    $new_length = strlen($new_data ?? '');
     $this->reserveBytes($new_length * 5 / 4);
 
     if ($new_data === null) {
