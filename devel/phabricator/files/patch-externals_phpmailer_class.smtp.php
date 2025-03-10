--- externals/phpmailer/class.smtp.php.orig	2024-12-03 14:44:25 UTC
+++ externals/phpmailer/class.smtp.php
@@ -385,7 +385,7 @@ class SMTP {
 
     $max_line_length = 998; // used below; set here for ease in change
 
-    while(list(,$line) = @each($lines)) {
+    foreach($lines as $line) {
       $lines_out = null;
       if($line == "" && $in_headers) {
         $in_headers = false;
@@ -414,7 +414,7 @@ class SMTP {
       $lines_out[] = $line;
 
       // send the lines to the server
-      while(list(,$line_out) = @each($lines_out)) {
+      foreach($lines_out as $line_out) {
         if(strlen($line_out) > 0)
         {
           if(substr($line_out, 0, 1) == ".") {
