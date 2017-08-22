--- api/rest/swagger/index.php	2017-06-18 00:46:15.000000000 +0300
+++ api/rest/swagger/index.php	2017-02-24 08:29:06.000000000 +0300
@@ -1,3 +1,8 @@
+<?php
+$g_bypass_headers = true;
+require_once( __DIR__ . '/../../../core.php' );
+$t_path = config_get( 'path' );
+?>
 <!DOCTYPE html>
 <html>
 <head>
@@ -38,7 +43,7 @@
       if (url && url.length > 1) {
         url = decodeURIComponent(url[1]);
       } else {
-        url = "http://petstore.swagger.io/v2/swagger.json";
+        url = '<?php echo $t_path . 'api/rest/swagger.json' ?>';
       }
 
       hljs.configure({
