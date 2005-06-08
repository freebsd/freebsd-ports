--- pear/scripts/pearcmd.php.orig	Sun Jun  6 17:52:41 2004
+++ pear/scripts/pearcmd.php	Mon Jul 12 16:22:50 2004
@@ -1,3 +1,4 @@
+#!%%PREFIX%%/bin/php -nq
 <?php
 //
 // +----------------------------------------------------------------------+
@@ -24,9 +25,9 @@
 /**
  * @nodep Gtk
  */
-if ('@include_path@' != '@'.'include_path'.'@') {
-    ini_set('include_path', '@include_path@');
-}
+dl('pcre.so');
+dl('xml.so');
+ini_set('include_path', '%%PREFIX%%/share/pear:%%PREFIX%%/share/pear/bootstrap');
 ini_set('allow_url_fopen', true);
 if (!ini_get('safe_mode')) {
     set_time_limit(0);
