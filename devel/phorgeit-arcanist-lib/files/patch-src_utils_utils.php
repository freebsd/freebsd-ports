--- src/utils/utils.php.orig	2026-06-25 22:33:39 UTC
+++ src/utils/utils.php
@@ -372,10 +372,12 @@ function igroup(array $list, $by, ...$indices) {
 
   $groups = array();
   foreach ($map as $group) {
+    $group = $group ?? '';
     $groups[$group] = array();
   }
 
   foreach ($map as $key => $group) {
+    $group = $group ?? '';
     $groups[$group][$key] = $list[$key];
   }
 
