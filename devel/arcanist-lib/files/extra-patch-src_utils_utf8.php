--- src/utils/utf8.php.orig	2025-11-28 10:05:46 UTC
+++ src/utils/utf8.php
@@ -288,9 +288,6 @@ function phutil_utf8_strlen($string) {
  * @return int   The character length of the string.
  */
 function phutil_utf8_strlen($string) {
-  if (function_exists('utf8_decode')) {
-    return strlen(utf8_decode($string));
-  }
   return count(phutil_utf8v($string));
 }
 
