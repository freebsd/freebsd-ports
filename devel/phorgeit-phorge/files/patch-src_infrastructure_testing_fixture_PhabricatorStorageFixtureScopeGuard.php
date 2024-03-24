--- src/infrastructure/testing/fixture/PhabricatorStorageFixtureScopeGuard.php.orig	2020-05-19 10:51:50 UTC
+++ src/infrastructure/testing/fixture/PhabricatorStorageFixtureScopeGuard.php
@@ -11,7 +11,7 @@ final class PhabricatorStorageFixtureScopeGuard extend
     $this->name = $name;
 
     execx(
-      'php %s upgrade --force --namespace %s',
+      '%%PHP_CMD%% %s upgrade --force --namespace %s',
       $this->getStorageBinPath(),
       $this->name);
 
@@ -30,7 +30,7 @@ final class PhabricatorStorageFixtureScopeGuard extend
     PhabricatorLiskDAO::closeAllConnections();
 
     execx(
-      'php %s destroy --force --namespace %s',
+      '%%PHP_CMD%% %s destroy --force --namespace %s',
       $this->getStorageBinPath(),
       $this->name);
   }
