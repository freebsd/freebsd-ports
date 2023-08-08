--- src/infrastructure/markup/blockrule/PhutilRemarkupListBlockRule.php.orig	2021-12-18 19:11:09 UTC
+++ src/infrastructure/markup/blockrule/PhutilRemarkupListBlockRule.php
@@ -446,7 +446,7 @@ final class PhutilRemarkupListBlockRule extends Phutil
       }
 
       $start_attr = null;
-      if (ctype_digit($starts_at) && $starts_at > 1) {
+      if ((is_int($starts_at) || ctype_digit($starts_at)) && $starts_at > 1) {
         $start_attr = hsprintf(' start="%d"', $starts_at);
       }
 
