--- PEAR/Config.php.orig	2020-04-19 18:02:46 UTC
+++ PEAR/Config.php
@@ -28,7 +28,7 @@ require_once 'System.php';
  */
 $GLOBALS['_PEAR_Config_instance'] = null;
 if (!defined('PEAR_INSTALL_DIR') || !PEAR_INSTALL_DIR) {
-    $PEAR_INSTALL_DIR = PHP_LIBDIR . DIRECTORY_SEPARATOR . 'pear';
+    $PEAR_INSTALL_DIR = PHP_PREFIX . DIRECTORY_SEPARATOR . 'share' . DIRECTORY_SEPARATOR . 'pear';
 } else {
     $PEAR_INSTALL_DIR = PEAR_INSTALL_DIR;
 }
@@ -114,7 +114,7 @@ if (getenv('PHP_PEAR_DOC_DIR')) {
     define('PEAR_CONFIG_DEFAULT_DOC_DIR', getenv('PHP_PEAR_DOC_DIR'));
 } else {
     define('PEAR_CONFIG_DEFAULT_DOC_DIR',
-           $PEAR_INSTALL_DIR.DIRECTORY_SEPARATOR.'docs');
+           PHP_PREFIX.DIRECTORY_SEPARATOR.'share'.DIRECTORY_SEPARATOR.'doc'.DIRECTORY_SEPARATOR.'pear');
 }
 
 // Default for bin_dir
@@ -137,7 +137,7 @@ if (getenv('PHP_PEAR_CFG_DIR')) {
     define('PEAR_CONFIG_DEFAULT_CFG_DIR', getenv('PHP_PEAR_CFG_DIR'));
 } else {
     define('PEAR_CONFIG_DEFAULT_CFG_DIR',
-           $PEAR_INSTALL_DIR.DIRECTORY_SEPARATOR.'cfg');
+           PHP_PREFIX.DIRECTORY_SEPARATOR.'etc'.DIRECTORY_SEPARATOR.'pear');
 }
 
 // Default for www_dir
@@ -145,7 +145,7 @@ if (getenv('PHP_PEAR_WWW_DIR')) {
     define('PEAR_CONFIG_DEFAULT_WWW_DIR', getenv('PHP_PEAR_WWW_DIR'));
 } else {
     define('PEAR_CONFIG_DEFAULT_WWW_DIR',
-           $PEAR_INSTALL_DIR.DIRECTORY_SEPARATOR.'www');
+           PHP_PREFIX.DIRECTORY_SEPARATOR.'www');
 }
 
 // Default for man_dir
