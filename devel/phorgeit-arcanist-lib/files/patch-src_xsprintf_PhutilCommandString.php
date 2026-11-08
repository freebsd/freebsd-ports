--- src/xsprintf/PhutilCommandString.php.orig	2026-06-25 22:33:39 UTC
+++ src/xsprintf/PhutilCommandString.php
@@ -56,12 +56,8 @@ final class PhutilCommandString extends Phobject {
       }
     }
 
-    // Be generous about what we accept
-    // but normalize to a value that makes sense for a command line
-    // premising that CLIs only accept strings since that is how computers work
-    if ($value === null) {
-      $value = '';
-    }
+    // Cast PhutilCommandString and null to a string for further handling
+    $value = (string)$value;
 
     switch ($mode) {
       case self::MODE_LINUX:
@@ -76,7 +72,7 @@ final class PhutilCommandString extends Phobject {
   }
 
   private static function escapePowershell($value) {
-    // These escape sequences are from http://ss64.com/ps/syntax-esc.html
+    // These escape sequences are from https://ss64.com/ps/syntax-esc.html
 
     // Replace backticks first.
     $value = str_replace('`', '``', $value);
