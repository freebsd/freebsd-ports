--- src/applications/pholio/remarkup/PholioRemarkupRule.php.orig	2020-11-19 21:48:33 UTC
+++ src/applications/pholio/remarkup/PholioRemarkupRule.php
@@ -75,6 +75,8 @@ final class PholioRemarkupRule extends PhabricatorObje
       $opts = $parser->parse(substr($options, 1));
 
       if (isset($opts['image'])) {
+        // PholioMockEmbedView shows only the first image passed.
+        // Keep "&" syntax for backwards compatibility.
         $images = array_unique(
           explode('&', preg_replace('/\s+/', '', $opts['image'])));
 
