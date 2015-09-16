--- src/workflow/ArcanistVersionWorkflow.php.orig	2015-07-14 00:07:20.409019999 +0200
+++ src/workflow/ArcanistVersionWorkflow.php	2015-07-14 00:27:09.586063998 +0200
@@ -27,6 +27,13 @@
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
