--- externals/phpmailer/class.phpmailer.php.orig	2024-12-03 14:44:25 UTC
+++ externals/phpmailer/class.phpmailer.php
@@ -1624,7 +1624,7 @@ class PHPMailer {
     $eol = "\r\n";
     $escape = '=';
     $output = '';
-    while( list(, $line) = each($lines) ) {
+    foreach ($lines as $line) {
       $linlen = strlen($line);
       $newline = '';
       for($i = 0; $i < $linlen; $i++) {
