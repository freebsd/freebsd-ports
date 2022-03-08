--- src/toolset/workflow/ArcanistShellCompleteWorkflow.php.orig	2022-03-04 18:34:34 UTC
+++ src/toolset/workflow/ArcanistShellCompleteWorkflow.php
@@ -92,7 +92,7 @@ EOTEXT
     $argv = $this->getArgument('argv');
 
     $is_generate = $this->getArgument('generate');
-    $is_shell = (bool)strlen($this->getArgument('shell'));
+    $is_shell = $this->getArgument('shell') != null;
     $is_current = $this->getArgument('current');
 
     if ($argv) {
