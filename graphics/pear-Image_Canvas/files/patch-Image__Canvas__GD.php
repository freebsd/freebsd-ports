--- ./Image/Canvas/GD.php.orig	2010-05-15 11:53:04.000000000 +0200
+++ ./Image/Canvas/GD.php	2010-05-15 11:53:04.000000000 +0200
@@ -1770,7 +1770,7 @@
             $php_info = ob_get_contents();
             ob_end_clean();
 
-            if (ereg("<td[^>]*>GD Version *<\/td><td[^>]*>([^<]*)<\/td>",
+            if (preg_match("/<td[^>]*>GD Version *<\/td><td[^>]*>([^<]*)<\/td>/",
                 $php_info, $result))
             {
                 $version = $result[1];
@@ -1779,9 +1779,9 @@
             }
         }
 
-        if (ereg('1\.[0-9]{1,2}', $version)) {
+        if (preg_match('/1\.[0-9]{1,2}/', $version)) {
             return 1;
-        } elseif (ereg('2\.[0-9]{1,2}', $version)) {
+        } elseif (preg_match('/2\.[0-9]{1,2}/', $version)) {
             return 2;
         } else {
             return 0;
