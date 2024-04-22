--- src/workflow/ArcanistAnoidWorkflow.php.orig	2020-05-14 23:31:28 UTC
+++ src/workflow/ArcanistAnoidWorkflow.php
@@ -24,11 +24,10 @@ EOTEXT
   }
 
   public function runWorkflow() {
-    if (!Filesystem::binaryExists('python3')) {
+    if (!Filesystem::binaryExists('%%PYTHON_CMD%%')) {
       throw new PhutilArgumentUsageException(
         pht(
-          'The "arc anoid" workflow requires "python3" to be available '.
-          'in your $PATH.'));
+          'The "arc anoid" workflow requires "%%PYTHON_CMD%%" to be available.'));
     }
 
     $support_dir = phutil_get_library_root('arcanist');
