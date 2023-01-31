--- src/applications/diffusion/conduit/DiffusionHistoryQueryConduitAPIMethod.php.orig	2021-12-18 19:11:09 UTC
+++ src/applications/diffusion/conduit/DiffusionHistoryQueryConduitAPIMethod.php
@@ -55,7 +55,7 @@ final class DiffusionHistoryQueryConduitAPIMethod
     $limit = $request->getValue('limit');
 
     if (strlen($against_hash)) {
-      $commit_range = "${against_hash}..${commit_hash}";
+      $commit_range = "{$against_hash}..{$commit_hash}";
     } else {
       $commit_range = $commit_hash;
     }
