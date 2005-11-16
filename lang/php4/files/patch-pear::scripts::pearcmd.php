--- pear/scripts/pearcmd.php.orig	Mon Mar 28 18:57:01 2005
+++ pear/scripts/pearcmd.php	Tue Nov 15 23:25:55 2005
@@ -1,3 +1,4 @@
+#!%%PREFIX%%/bin/php -nq
 <?php
 //
 // +----------------------------------------------------------------------+
@@ -24,9 +25,10 @@
 /**
  * @nodep Gtk
  */
-if ('@include_path@' != '@'.'include_path'.'@') {
-    ini_set('include_path', '@include_path@');
-}
+dl('pcre.so');
+dl('xml.so');
+ini_set('include_path', '%%PREFIX%%/share/pear:%%PREFIX%%/share/pear/bootstrap');
+ini_set('memory_limit', '16M');
 ini_set('allow_url_fopen', true);
 if (!ini_get('safe_mode')) {
     @set_time_limit(0);
