--- src/moduleutils/PhutilLibraryMapBuilder.php.orig	2020-05-19 10:41:00 UTC
+++ src/moduleutils/PhutilLibraryMapBuilder.php
@@ -268,7 +268,7 @@ final class PhutilLibraryMapBuilder extends Phobject {
     $absolute_file = $this->getPath($file);
     $bin = dirname(__FILE__).'/../../support/lib/extract-symbols.php';
 
-    return new ExecFuture('php -f %R -- --ugly %R', $bin, $absolute_file);
+    return new ExecFuture('%%PHP_CMD%% -f %R -- --ugly %R', $bin, $absolute_file);
   }
 
 
