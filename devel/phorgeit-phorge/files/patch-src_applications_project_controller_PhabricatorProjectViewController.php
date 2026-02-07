--- src/applications/project/controller/PhabricatorProjectViewController.php.orig	2022-01-26 14:24:00 UTC
+++ src/applications/project/controller/PhabricatorProjectViewController.php
@@ -39,7 +39,7 @@ final class PhabricatorProjectViewController
         $controller_object = new PhabricatorProjectManageController();
         break;
       default:
-        return $engine->buildResponse();
+        return $engine->buildResponse(true);
     }
 
     return $this->delegateToController($controller_object);
