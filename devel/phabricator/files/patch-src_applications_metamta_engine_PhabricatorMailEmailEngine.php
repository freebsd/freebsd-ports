--- src/applications/metamta/engine/PhabricatorMailEmailEngine.php.orig	2021-12-18 19:11:09 UTC
+++ src/applications/metamta/engine/PhabricatorMailEmailEngine.php
@@ -80,7 +80,7 @@ final class PhabricatorMailEmailEngine
     if ($stamps) {
       $headers[] = $this->newEmailHeader(
         'X-Phabricator-Stamps',
-        implode(' ', $stamps));
+        wordwrap(implode(' ', $stamps), 800, "\n\t"));
     }
 
     $must_encrypt = $mail->getMustEncrypt();
