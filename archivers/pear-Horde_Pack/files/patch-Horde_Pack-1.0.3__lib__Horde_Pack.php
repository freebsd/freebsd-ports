--- Horde_Pack-1.0.3/lib/Horde/Pack.php.orig	2014-09-03 12:17:27.201458631 +0200
+++ Horde_Pack-1.0.3/lib/Horde/Pack.php	2014-09-03 12:19:10.869687370 +0200
@@ -49,18 +49,19 @@
     public function __construct()
     {
         if (empty(self::$_drivers)) {
-            $fi = new FilesystemIterator(__DIR__ . '/Pack/Driver');
             $class_prefix = __CLASS__ . '_Driver_';
 
-            foreach ($fi as $val) {
-                if ($val->isFile()) {
-                    $cname = $class_prefix . $val->getBasename('.php');
+            $handle = opendir(__DIR__ . '/Pack/Driver');
+            while ($val = readdir($handle)) {
+                if (is_file(__DIR__ . '/Pack/Driver/' . $val)) {
+                    $cname = $class_prefix . basename($val,'.php');
                     if (class_exists($cname) && $cname::supported()) {
                         $ob = new $cname();
                         self::$_drivers[$ob->id] = $ob;
                     }
                 }
             }
+            closedir($handle);
 
             krsort(self::$_drivers, SORT_NUMERIC);
 
