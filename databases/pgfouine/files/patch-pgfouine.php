--- pgfouine.php.orig	2008-05-06 13:53:52.000000000 +0200
+++ pgfouine.php	2008-05-06 13:54:32.000000000 +0200
@@ -32,6 +32,8 @@ if(strpos(phpversion(), '4.4') === 0) {
 	error_reporting(E_ALL);
 }
 
+ini_set('include_path', '!!PREFIX!!/share/pgfouine');
+
 include('version.php');
 require_once('include/lib/common.lib.php');
 require_once('include/base.lib.php');
