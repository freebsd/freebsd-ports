--- mapscript/php/image.c.orig	2012-09-05 14:29:49.000000000 +0800
+++ mapscript/php/image.c	2012-09-05 14:31:04.000000000 +0800
@@ -303,11 +303,18 @@
     /* no filename - read stdout */
 
     /* if there is no output buffer active, set the header */
-    if (OG(ob_nesting_level)<=0)
-    {
-        php_header(TSRMLS_C);
-    }
-   
+    //handle changes in PHP 5.4.x
+    #if PHP_VERSION_ID < 50399
+      if (OG(ob_nesting_level)<=0)
+      {
+          php_header(TSRMLS_C);
+      }
+    #else
+      if (php_output_get_level(TSRMLS_C)<=0)
+      {
+          php_header(TSRMLS_C);
+      }
+    #endif   
 
     if (MS_RENDERER_PLUGIN(php_image->image->format))
     {
