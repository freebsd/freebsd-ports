--- scripts/pearcmd.php.orig	Wed Oct 27 02:58:21 2004
+++ scripts/pearcmd.php	Thu Dec 16 17:30:19 2004
@@ -1,3 +1,4 @@
+#!@php_bin@ -nq
 <?php
 //
 // +----------------------------------------------------------------------+
@@ -24,8 +25,11 @@
 /**
  * @nodep Gtk
  */
+dl('pcre.so');
+dl('xml.so');
+
 if ('@include_path@' != '@'.'include_path'.'@') {
-    ini_set('include_path', '@include_path@');
+    ini_set('include_path', '@include_path@:@include_path@/bootstrap');
 }
 ini_set('allow_url_fopen', true);
 if (!ini_get('safe_mode')) {
