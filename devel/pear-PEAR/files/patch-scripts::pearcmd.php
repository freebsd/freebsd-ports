--- scripts/pearcmd.php.orig	Thu Oct 28 14:37:56 2004
+++ scripts/pearcmd.php	Thu Nov 11 11:21:39 2004
@@ -1,3 +1,4 @@
+#!@php_bin@ -q -dsafe_mode=0 -doutput_buffering=1
 <?php
 //
 // +----------------------------------------------------------------------+
@@ -24,8 +25,10 @@
 /**
  * @nodep Gtk
  */
+dl('pcre.so');
+dl('xml.so');
 if ('@include_path@' != '@'.'include_path'.'@') {
-    ini_set('include_path', '@include_path@');
+    ini_set('include_path', '@include_path@:@include_path@/bootstrap');
 }
 ini_set('allow_url_fopen', true);
 if (!ini_get('safe_mode')) {
