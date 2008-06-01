--- pgfouine_vacuum.php.orig	2008-05-06 13:54:43.000000000 +0200
+++ pgfouine_vacuum.php	2008-05-06 13:55:02.000000000 +0200
@@ -30,6 +30,8 @@ if(strpos(phpversion(), '4.4') === 0) {
 	error_reporting(E_ALL);
 }
 
+ini_set('include_path', '!!PREFIX!!/share/pgfouine');
+
 include('version.php');
 require_once('include/lib/common.lib.php');
 require_once('include/base.lib.php');
