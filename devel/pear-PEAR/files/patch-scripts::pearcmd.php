--- scripts/pearcmd.php.orig	Wed Oct 27 02:58:21 2004
+++ scripts/pearcmd.php	Tue Dec 14 14:56:46 2004
@@ -1,3 +1,4 @@
+#!@php_bin@ -q -dsafe_mode=0 -doutput_buffering=1
 <?php
 //
 // +----------------------------------------------------------------------+
@@ -24,8 +25,14 @@
 /**
  * @nodep Gtk
  */
+if (!extension_loaded('pcre')) {
+    dl('pcre.so');
+}
+if (!extension_loaded('xml')) {
+    dl('xml.so');
+}
 if ('@include_path@' != '@'.'include_path'.'@') {
-    ini_set('include_path', '@include_path@');
+    ini_set('include_path', '@include_path@:@include_path@/bootstrap');
 }
 ini_set('allow_url_fopen', true);
 if (!ini_get('safe_mode')) {
