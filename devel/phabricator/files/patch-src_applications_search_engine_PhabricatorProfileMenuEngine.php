--- src/applications/search/engine/PhabricatorProfileMenuEngine.php.orig	2022-01-26 14:23:11 UTC
+++ src/applications/search/engine/PhabricatorProfileMenuEngine.php
@@ -99,7 +99,7 @@ abstract class PhabricatorProfileMenuEngine extends Ph
     return $this->editMode;
   }
 
-  public function buildResponse() {
+  public function buildResponse($ignore_item_id = false) {
     $controller = $this->getController();
 
     $viewer = $controller->getViewer();
@@ -130,6 +130,10 @@ abstract class PhabricatorProfileMenuEngine extends Ph
       $item_id = $request->getURIData('id');
     }
 
+    if ($ignore_item_id) {
+      $item_id = "";
+    }
+
     $view_list = $this->newProfileMenuItemViewList();
 
     if ($is_view) {
