--- src/applications/project/editor/PhabricatorProjectTransactionEditor.php.orig	2021-12-18 19:11:09 UTC
+++ src/applications/project/editor/PhabricatorProjectTransactionEditor.php
@@ -352,10 +352,32 @@ final class PhabricatorProjectTransactionEditor
       // parent project, since this is the governing rule.
 
       $parent = $copy->getParentProject();
+      if ($parent != null) {
+        $parent_phid = $parent->getPHID();
+      } else { // can happen when using conduit API
+          foreach ($xactions as $xaction) {
+            if ($xaction->getTransactionType() != PhabricatorProjectMilestoneTransaction::TRANSACTIONTYPE) {
+              continue;
+            }
+            $parent_phid = (string)$xaction->getNewValue();
+            $project = id(new PhabricatorProjectQuery())
+              ->setViewer($this->getActor())
+              ->withPHIDs(array($parent_phid))
+              ->requireCapabilities(
+                array(
+                  PhabricatorPolicyCapability::CAN_VIEW,
+                  PhabricatorPolicyCapability::CAN_EDIT,
+                ))
+              ->executeOne();
 
+            $copy->attachParentProject($project);
+            $copy->setParentProjectPHID($parent_phid);
+        }
+      }
+
       $parent = id(new PhabricatorProjectQuery())
         ->setViewer($this->getActor())
-        ->withPHIDs(array($parent->getPHID()))
+        ->withPHIDs(array($parent_phid))
         ->needMembers(true)
         ->executeOne();
       $members = $parent->getMemberPHIDs();
