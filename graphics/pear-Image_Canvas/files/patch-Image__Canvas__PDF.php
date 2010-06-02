--- ./Image/Canvas/PDF.php.orig	2010-05-15 11:53:04.000000000 +0200
+++ ./Image/Canvas/PDF.php	2010-05-15 11:53:04.000000000 +0200
@@ -993,14 +993,14 @@
             $php_info = ob_get_contents();
             ob_end_clean();
 
-            if (ereg("<td[^>]*>PDFlib GmbH Version *<\/td><td[^>]*>([^<]*)<\/td>",
+            if (preg_match("/<td[^>]*>PDFlib GmbH Version *<\/td><td[^>]*>([^<]*)<\/td>/",
                 $php_info, $result))
             {
                 $version = $result[1];
             }
         }               
         
-        if (ereg('([0-9]{1,2})\.[0-9]{1,2}(\.[0-9]{1,2})?', trim($version), $result)) {
+        if (preg_match('/([0-9]{1,2})\.[0-9]{1,2}(\.[0-9]{1,2})?/', trim($version), $result)) {
             return $result[1];
         } else {
             return $version;
