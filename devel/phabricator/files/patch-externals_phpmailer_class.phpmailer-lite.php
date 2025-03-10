--- externals/phpmailer/class.phpmailer-lite.php.orig	2024-12-03 14:44:25 UTC
+++ externals/phpmailer/class.phpmailer-lite.php
@@ -1492,7 +1492,7 @@ class PHPMailerLite {
     $eol = "\r\n";
     $escape = '=';
     $output = '';
-    while( list(, $line) = each($lines) ) {
+    foreach ($lines as $line) {
       $linlen = strlen($line);
       $newline = '';
       for($i = 0; $i < $linlen; $i++) {
