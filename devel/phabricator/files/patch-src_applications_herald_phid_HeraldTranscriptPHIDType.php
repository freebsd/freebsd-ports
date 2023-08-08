--- src/applications/herald/phid/HeraldTranscriptPHIDType.php.orig	2021-12-18 19:11:09 UTC
+++ src/applications/herald/phid/HeraldTranscriptPHIDType.php
@@ -35,7 +35,7 @@ final class HeraldTranscriptPHIDType extends Phabricat
       $id = $xscript->getID();
 
       $handle->setName(pht('Transcript %s', $id));
-      $handle->setURI("/herald/transcript/${id}/");
+      $handle->setURI("/herald/transcript/{$id}/");
     }
   }
 
