--- src/repository/api/ArcanistGitAPI.php.orig	2023-01-06 17:27:38 UTC
+++ src/repository/api/ArcanistGitAPI.php
@@ -1143,7 +1143,7 @@ final class ArcanistGitAPI extends ArcanistRepositoryA
 
   public function hasLocalCommit($commit) {
     try {
-      if (!$this->getCanonicalRevisionName($commit)) {
+      if (!$this->getCanonicalRevisionName($commit ?? '')) {
         return false;
       }
     } catch (CommandException $exception) {
