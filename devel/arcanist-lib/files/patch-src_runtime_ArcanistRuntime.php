--- src/runtime/ArcanistRuntime.php.orig	2020-05-19 10:39:08 UTC
+++ src/runtime/ArcanistRuntime.php
@@ -206,7 +206,7 @@ final class ArcanistRuntime {
     $bin = $arcanist_root.'/scripts/arcanist.php';
 
     $err = phutil_passthru(
-      'php -f %R -- %Ls',
+      '%%PHP_CMD%% -f %R -- %Ls',
       $bin,
       array_slice($argv, 1));
 
