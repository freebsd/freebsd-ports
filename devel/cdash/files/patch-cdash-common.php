--- cdash/common.php.orig	2015-08-05 14:20:51.000000000 +0000
+++ cdash/common.php	2015-08-05 14:21:39.038187339 +0000
@@ -20,6 +20,7 @@
 
 if (PHP_VERSION >= 5) {
     // Emulate the old xslt library functions
+    libxml_disable_entity_loader(false);
     function xslt_create() {
         return new XsltProcessor();
     }
