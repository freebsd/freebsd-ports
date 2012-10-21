--- includes/fix.inc.php	2012-09-30 17:46:29.000000000 +0100
+++ includes/fix.inc.php	2012-09-30 17:47:08.000000000 +0100
@@ -13,7 +13,7 @@
 
 defined('E_DEPRECATED') || define('E_DEPRECATED', 8192);
 
-error_reporting(E_ALL);
+error_reporting(E_ALL & ~E_STRICT);
 
 // our default charset
 
