--- ./Image/Canvas.php.orig	2010-05-15 11:53:04.000000000 +0200
+++ ./Image/Canvas.php	2010-05-15 11:53:51.000000000 +0200
@@ -730,7 +730,7 @@
 
                 $error  = 'PHP extension ming is required for output in swf format.';
                 $error .= 'Please install the ming extension (http://de.php.net/ming).';
-                $error  =& new PEAR_Error($error);
+                $error  = new PEAR_Error($error);
                 return $error;
             }
         }
@@ -742,7 +742,7 @@
         $class = 'Image_Canvas_'. $canvas;
         include_once 'Image/Canvas/'. str_replace('_', '/', $canvas) . '.php';
         
-        $obj =& new $class($params);
+        $obj = new $class($params);
         return $obj;
     }
 
