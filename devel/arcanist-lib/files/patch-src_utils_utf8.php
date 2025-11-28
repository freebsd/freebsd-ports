--- src/utils/utf8.php.orig	2022-05-17 23:20:14 UTC
+++ src/utils/utf8.php
@@ -288,8 +288,12 @@ function phutil_utf8_strlen($string) {
  * @return int   The character length of the string.
  */
 function phutil_utf8_strlen($string) {
-  if (function_exists('utf8_decode')) {
-    return strlen(utf8_decode($string));
+  if (function_exists('mb_strlen')) {
+    // Historically, this was just a call to strlen(utf8_decode(
+    // but, since PHP 8.2, that function is deprecated, so this is
+    // the current equivalent.
+    // https://we.phorge.it/T15188
+    return mb_strlen($string, 'UTF-8');
   }
   return count(phutil_utf8v($string));
 }
