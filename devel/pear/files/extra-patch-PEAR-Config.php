--- PEAR/Config.php.orig	2011-11-15 10:23:32.384650640 +0100
+++ PEAR/Config.php	2011-11-15 10:23:35.145650207 +0100
@@ -29,7 +29,7 @@
  */
 $GLOBALS['_PEAR_Config_instance'] = null;
 if (!defined('PEAR_INSTALL_DIR') || !PEAR_INSTALL_DIR) {
-    $PEAR_INSTALL_DIR = PHP_LIBDIR . DIRECTORY_SEPARATOR . 'pear';
+    $PEAR_INSTALL_DIR = PHP_PREFIX . DIRECTORY_SEPARATOR . 'share' . DIRECTORY_SEPARATOR . 'pear';
 } else {
     $PEAR_INSTALL_DIR = PEAR_INSTALL_DIR;
 }
@@ -108,7 +108,7 @@
     define('PEAR_CONFIG_DEFAULT_DOC_DIR', getenv('PHP_PEAR_DOC_DIR'));
 } else {
     define('PEAR_CONFIG_DEFAULT_DOC_DIR',
-           $PEAR_INSTALL_DIR.DIRECTORY_SEPARATOR.'docs');
+           PHP_PREFIX.DIRECTORY_SEPARATOR.'share'.DIRECTORY_SEPARATOR.'doc'.DIRECTORY_SEPARATOR.'pear');
 }
 
 // Default for bin_dir
@@ -131,7 +131,7 @@
     define('PEAR_CONFIG_DEFAULT_CFG_DIR', getenv('PHP_PEAR_CFG_DIR'));
 } else {
     define('PEAR_CONFIG_DEFAULT_CFG_DIR',
-           $PEAR_INSTALL_DIR.DIRECTORY_SEPARATOR.'cfg');
+           PHP_PREFIX.DIRECTORY_SEPARATOR.'etc'.DIRECTORY_SEPARATOR.'pear');
 }
 
 // Default for www_dir
@@ -139,7 +139,7 @@
     define('PEAR_CONFIG_DEFAULT_WWW_DIR', getenv('PHP_PEAR_WWW_DIR'));
 } else {
     define('PEAR_CONFIG_DEFAULT_WWW_DIR',
-           $PEAR_INSTALL_DIR.DIRECTORY_SEPARATOR.'www');
+           PHP_PREFIX.DIRECTORY_SEPARATOR.'www');
 }
 
 // Default for test_dir
