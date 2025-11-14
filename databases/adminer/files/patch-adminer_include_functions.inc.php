--- adminer/include/functions.inc.php.orig	2025-10-19 12:05 UTC
+++ adminer/include/functions.inc.php
@@ -761,7 +761,7 @@
 * @return string 32 hexadecimal characters
 */
 function rand_string(): string {
-	return md5(uniqid(strval(mt_rand()), true));
+	return bin2hex(random_bytes(32));
 }
 
 /** Format value to use in select
