--- scripts/pearcmd.php.orig	Sun Nov  6 21:17:11 2005
+++ scripts/pearcmd.php	Sun Nov  6 21:19:20 2005
@@ -1,3 +1,4 @@
+#!@php_bin@ -nq
 <?php
 //
 // +----------------------------------------------------------------------+
@@ -29,8 +30,10 @@
 /**
  * @nodep Gtk
  */
+dl('pcre.so');
+dl('xml.so');
 if ('@include_path@' != '@'.'include_path'.'@') {
-    ini_set('include_path', '@include_path@');
+    ini_set('include_path', '@include_path@:@include_path@/bootstrap');
     $raw = false;
 } else {
     // this is a raw, uninstalled pear, either a cvs checkout, or php distro
