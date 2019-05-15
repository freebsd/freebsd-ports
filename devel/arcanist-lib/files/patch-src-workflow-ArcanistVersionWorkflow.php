--- src/workflow/ArcanistVersionWorkflow.php.orig	2017-06-09 15:12:37 UTC
+++ src/workflow/ArcanistVersionWorkflow.php
@@ -27,6 +27,13 @@ EOTEXT
   public function run() {
     $console = PhutilConsole::getConsole();
 
+    $versions = array();
+    exec("pkg query '%n %v (%o)' php5-arcanist php5-libphutil", $versions);
+    foreach ($versions as $pkg) {
+      $console->writeOut($pkg."\n");
+    }
+    return;
+
     if (!Filesystem::binaryExists('git')) {
       throw new ArcanistUsageException(
         pht(
