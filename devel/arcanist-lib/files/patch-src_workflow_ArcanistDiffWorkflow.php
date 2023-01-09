--- src/workflow/ArcanistDiffWorkflow.php.orig	2023-01-09 21:24:25 UTC
+++ src/workflow/ArcanistDiffWorkflow.php
@@ -2361,7 +2361,7 @@ EOTEXT
 
     // If we track an upstream branch either directly or indirectly, use that.
     $branch = $api->getBranchName();
-    if (strlen($branch)) {
+    if (strlen($branch ?? '')) {
       $upstream_path = $api->getPathToUpstream($branch);
       $remote_branch = $upstream_path->getRemoteBranchName();
       if ($remote_branch !== null) {
