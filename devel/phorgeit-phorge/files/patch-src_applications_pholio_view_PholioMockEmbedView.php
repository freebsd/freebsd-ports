--- src/applications/pholio/view/PholioMockEmbedView.php.orig	2020-11-19 21:48:33 UTC
+++ src/applications/pholio/view/PholioMockEmbedView.php
@@ -25,7 +25,8 @@ final class PholioMockEmbedView extends AphrontView {
     $thumbnail = null;
     if (!empty($this->images)) {
       $images_to_show = array_intersect_key(
-        $this->mock->getActiveImages(), array_flip($this->images));
+        mpull($mock->getActiveImages(), null, 'getID'),
+        array_flip($this->images));
     }
 
     $xform = PhabricatorFileTransform::getTransformByKey(
