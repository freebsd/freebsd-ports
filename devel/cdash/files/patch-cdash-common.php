--- cdash/common.php.orig	2016-05-16 19:20:14 UTC
+++ cdash/common.php
@@ -20,6 +20,7 @@ require_once("cdash/log.php");
 
 if (PHP_VERSION >= 5) {
     // Emulate the old xslt library functions
+    libxml_disable_entity_loader(false);
     function xslt_create() {
         return new XsltProcessor();
     }
