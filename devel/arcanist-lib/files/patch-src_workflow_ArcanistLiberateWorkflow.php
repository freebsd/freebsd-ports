--- src/workflow/ArcanistLiberateWorkflow.php.orig	2020-05-19 10:37:58 UTC
+++ src/workflow/ArcanistLiberateWorkflow.php
@@ -148,7 +148,7 @@ EOTEXT
     }
 
     return phutil_passthru(
-      'php -f %R -- %Ls %R',
+      '%%PHP_CMD%% -f %R -- %Ls %R',
       $bin,
       $argv,
       $path);
